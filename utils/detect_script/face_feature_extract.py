#!/usr/bin/env python
# -*- coding: utf8 -*-

import base64
import datetime
import json
import logging
import logging.handlers
import operator
import os
import re
import requests
import signal
import sys
import threading
import time
import random
import commands
from Queue import Queue

fileList = Queue(maxsize=5000)
mutex = threading.Lock()
errormutext = threading.Lock()

reload(sys)
sys.setdefaultencoding("utf-8")

## global configure infomation
conf = dict(
        batch_num = 20,              # batch num
        thread_num = 20,             # thread num
        address = "http://192.168.2.21:8601/rec/image",
        #functions = [1,2,3,4,5,6,7,8,9,10,11,12],
        functions = [2,20,21],
        uri_header = 'http://192.168.2.21:3002/faceimage',
        photo_path = "test",       # image path
        mode = 0,                   # 0 means single, 1 means batch
        uri_type = 1,               # 0 means local path, 1 means http path, 2 means encode to base64
        svr_type = 3,               # 1:car 2:face 3:all 0:default(face)
        timeout = 10,                # timeout
        requestID = 0,              # request Id
        interval = 1,               # stat interval
        onePass = 1,                #
        verbose = 1,                # 0 means closed
        duration = 0,               # how long to run, now default: never stop
        feature_file = "feature",   # feature files
        error_list = "feature/error.list",
        finished_file = "log/finished",
)

name1 = ['赵','钱','孙','李','周','吴','郑','王']
name2 = ['涛','高','红','倩','明','浩','华','晨']


SESSION_ID = 0

#timeBound = (500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000)
timeBound = (200, 300, 400, 500, 600, 800, 1000, 1500, 2000, 5000)
#timeBound = (200, 400, 500, 600, 700, 800, 1000, 1500, 2000, 5000)
carNumBound = (1, 2, 3, 5, 10, 20)


## init log
logger = logging.getLogger("MyLogger")
os.system("mkdir -p ./log")
log_name = "./log/matrix.restful.log." + str(conf["requestID"])
logging.basicConfig(level=logging.DEBUG,
           format='[%(asctime)s %(name)s %(levelname)s] %(message)s',
           #format='%(asctime)s %(filename)s[line:%(lineno)d] %(levelname)s %(message)s',
           datefmt='%Y-%m-%d %H:%M:%S',
           filename=log_name,
           filemode='w')
handler = logging.handlers.RotatingFileHandler(log_name,
            maxBytes = 20971520, backupCount = 5)
logger.addHandler(handler)
logger.setLevel(logging.DEBUG)
logger.info(
        "[[time.time:%s]]" % str(int(time.time())))
logger.info(
        "[[loadtest start at %s]]" % str(datetime.datetime.now()))
logger.info("Timeout Threshold: %dms", conf["timeout"])
logger.info("thread_num: %d", conf["thread_num"])


## global stat
stat = dict(
    timeDist = [0] * (len(timeBound) + 1),
    timeDistAll = [0] * (len(timeBound) + 1),

    carNumDist = [0] * (len(carNumBound) + 1),
    carNumDistAll = [0] * (len(carNumBound) + 1),

    httpCodeDist = [0]*1000,
    httpCodeDistAll = [0]*1000,

    statusCodeDist = [0]*1000,  #analyze matrix return code
    statusCodeDistAll = [0]*1000,

    requestCount = 0,
    requestCountAll = 0,
    requestTime = 0.0,
    requestTimeAll = 0.0,

    httpErrorCount = 0,
    httpErrorCountAll = 0,
    httpErrorTime = 0.0,
    httpErrorTimeAll = 0.0,

    max_qps = 0.0,
    min_qps = 1000000.0,
    max_time = 0.0,
    min_time = 1000000.0,

    timeoutCount = 0,
    timeoutCountAll = 0,
    timeoutTime = 0.0,
    timeoutTimeAll = 0.0,

    errorImageCount = 0,
    errorCount = 0,
    errorCountAll = 0,
    errorTime = 0.0,
    errorTimeAll = 0.0,

    carCount = 0,
    carCountAll = 0,
    plateCount = 0,
    plateCountAll = 0,
    colorCount = 0,
    colorCountAll = 0,

)


## query thread
class QueryThread(threading.Thread):
    def __init__(self, root_path, threadname):
        threading.Thread.__init__(self)
        self.setDaemon(True)
        self.root_path = root_path
        self.header = {"Content-type": "application/json"}
        self.functions = conf['functions']
        self.svr_type = conf['svr_type']
        self.stopped = False
        self.id = 0
        self.name = threadname
        fname = conf['feature_file'] + "/" + self.name + ".txt"
        if os.path.exists(fname):
            status, lineCnt = commands.getstatusoutput("cat " + fname + " | wc -l")
            self.id = int(lineCnt)


    def STOP(self):
        self.stopped = True

    def SingleReq(self, query):
        if len(query) == 0:
            return

        global SESSION_ID
        post_dict = {"Context": {"SessionId": 'singleReq_restful' + str(SESSION_ID), "Functions" : self.functions, "Type": self.svr_type}}
        SESSION_ID += 1

        logger.info("raw query:%s" %(query))
        query_dict = {}
        query = query[0]
        if conf['uri_type'] == 0:
            query_dict = {'URI': 'file:' + query}
        elif conf['uri_type'] == 1:
            query_dict =  {'URI': conf['uri_header'] + query[query.index('/'):]}
            #print query_dict
            #query_dict =  {'URI': URI_HEADER + '/' + query.split(MOUNT_PATH)[1]}
        elif conf['uri_type'] == 2:
             fd = open(query, "rb")
             file_encode = base64.b64encode(fd.read())
             fd.close()
             query_dict = {'BinData' : file_encode}
        post_dict['Image'] = {"Data": query_dict}
        return json.dumps(post_dict)

    def BatchReq(self, batchQuery):
        if len(batchQuery) == 0:
            return

        global SESSION_ID
        post_dict = {"Context": {"SessionId": 'batchReq_restful' + str(SESSION_ID), "Functions" : self.functions, "Type": self.svr_type}}
        SESSION_ID += 1
    
        batch_image = []
        for query in batchQuery:
            logger.info("raw query:%s" %(query))
            #print "raw query"
            #print query
            query_dict = {}
            if conf['uri_type'] == 0:
                query_dict = {'URI': 'file:' + query}
            elif conf['uri_type'] == 1:
                query_dict =  {'URI': conf['uri_header'] + query[query.index('/'):]}
            elif conf['uri_type'] == 2:
                fd = open(query, "rb")
                file_encode = base64.b64encode(fd.read())
                fd.close()
                query_dict = {'BinData' : file_encode}
            batch_image.append({"Data": query_dict})
        post_dict['Images'] = batch_image
        
        return json.dumps(post_dict)

    def Error(self, query):
        errormutext.acquire()
        with open(conf['error_list'], "a") as f:
            if type(query) is str: 
                stat['errorImageCount'] += 1
                f.write(query + '\n')
            else:
                for t in query: 
                    stat['errorImageCount'] += 1
                    f.write(t + '\n')
        errormutext.release()

    ## request once
    def Search(self, query):
        post_data = ""
        m_url = conf['address']

        ## single
        if conf['mode'] == 0:
            m_url = conf['address']
            post_data = self.SingleReq(query)
        ## batch
        elif conf['mode'] == 1:
            m_url = conf['address'] + '/batch'
            post_data = self.BatchReq(query)

        #print "===="* 10
        #print 'post_data'
        #print post_data
        #print "===="* 10
        begin = time.time()
        try:
            resp = requests.post(m_url, data=post_data, timeout=conf['timeout'])
        except:
            self.Error(query)

        end = time.time()

        #print "###"*20
        ##time.sleep(3)
        #print "###"*20

        #request count
        stat["requestCount"] += 1
        #time cost
        elapse = (end - begin) * 1000
        stat["requestTime"] += elapse

        #http return code
        resultCode = resp.status_code
        #print "http return code:%s" %(resp.status_code)
        stat["httpCodeDist"][resultCode] += 1

        #http error request
        if int(resultCode) != 200:
            #http error
            stat["httpErrorCount"] += 1
            stat["httpErrorTime"] += elapse

        if elapse > conf["timeout"] :
            stat["timeoutCount"] += 1
            stat["timeoutTime"] += elapse

        for (i, bound) in enumerate(timeBound) :
            if elapse < bound :
                stat["timeDist"][i] += 1
                break
        if elapse > timeBound[-1]:
            stat["timeDist"][-1] += 1


        stat["max_time"] = max(elapse, stat["max_time"])
        stat["min_time"] = min(elapse, stat["min_time"])

        #matrix return context
        resp_dict = {}
        try:
            resp_dict =  json.loads(resp.content)
        except:
            logger.error('json.loads(resp.content) error')
            #logger.error('json.loads(resp.content) error, resp.content:', resp.content)
            return


        #print '#'*50
        #print int(resultCode)
        #print resp_dict
        #print '-'*40
        results = []
        if conf['mode'] == 0:
            result = resp_dict['Result']
            results.append(result)
        elif conf['mode'] == 1:
            results = resp_dict['Results']
        #print 'Results Size:%d' %(len(results))
        for result in results:
            #print '*'*40
            #print result
            #print result['Vehicles']
            car_num  = len(result['Vehicles'])
            #print 'Car Num:%d' %(car_num)

            stat['carCount'] += car_num

            for (i, bound) in enumerate(carNumBound) :
                if car_num < bound :
                    stat["carNumDist"][i] += 1
                    break
            if car_num > carNumBound[-1]:
                stat["carNumDist"][-1] += 1
      
            for vehicle in result['Vehicles']:
                if vehicle.has_key('Color') and vehicle['Color'].has_key('ColorId'):
                    if vehicle['Color']['ColorId'] != -1:
                        stat['colorCount'] += 1
                    else:
                        logger.error('Color Error, ColorId=-1')
                        logger.error(str(vehicle))
                else:
                    logger.error('Color Error')
                    logger.error(str(vehicle))
                if vehicle.has_key('Plates') and len(vehicle['Plates']) != 0:
                        stat['plateCount'] += 1        
                else:
                    logger.error('Plates Error')
                    logger.error(str(vehicle))
      
        #time.sleep(1)

        #matrix return code
        if not resp_dict.has_key('Context'):
            logger.error('resp_dict does not has key Context')
            return
        if not resp_dict['Context'].has_key('Status'):
            logger.error('resp_dict[\'Context\'] does not has key Status')
            return
        if resp_dict['Context']['Status'] == '':
            logger.error('resp_dict[\'Context\'][\'Status\'] is empty')
            return
        returnCode = int(resp_dict['Context']['Status'])
        #print "deepv return code:%s" %(returnCode)
        stat["statusCodeDist"][returnCode] += 1
        if returnCode != 200:
        #if returnCode != 200 and resp_dict['Context'].has_key('Message'):
            #print "Debug###############"
            #print resp_dict
            #print resp_dict["Message"]
            logger.error('returnCode:%d' %(returnCode))
            logger.error(resp_dict)
        return eval(resp.content)

    def batch_run(self, batch_num):
        with open(conf['feature_file'] + "/" + self.name + ".txt", "a") as f:
            batch_list = []
            while True:
                mutex.acquire()
                while fileList.qsize() > 0 and len(batch_list) < batch_num:
                    batch_list.append(fileList.get())
                #print "queue size is", fileList.qsize()
                #print "batch_list.size is:", len(batch_list)
                mutex.release()
                if conf['mode'] == 0:
                    if len(batch_list) >= 1:
                        with open("log/" + self.name, "w") as procfile:
                            procfile.write(batch_list[0] + '\n')
                        r = self.Search(batch_list)
                        if r: 
                            if len(r['Result']['Pedestrian']) >0 and r['Result']['Pedestrian'][0].has_key('Face'):
                                feature = str(r['Result']['Pedestrian'][0]['Face']['Features'])
                                feature = feature.replace('\n','')
                                self.id += 1
                                f.write(str(self.id) + ' ' 
                                        + name1[random.randint(0, len(name1) - 1)] 
                                        + name2[random.randint(0, len(name2) - 1)] + ' '
                                        + conf['uri_header'] + batch_list[0][batch_list[0].index('/'):] + ' '
                                        + feature + '\n')
                            else:
                                self.Error(batch_list)
                        else:
                            self.Error(batch_list)
                        batch_list = []
                else:
                    if self.stopped == True or len(batch_list) >= batch_num: 
                        with open("log/" + self.name, "w") as procfile:
                            for i in range(0, len(batch_list)):
                                procfile.write(batch_list[i] + '\n')
                        r = self.Search(batch_list)
                        if r:
                            for i in range(0, len(batch_list)):
                                if len(r['Results'][i]['Pedestrian']) > 0 and r['Results'][i]['Pedestrian'][0].has_key('Face'):
                                    feature = str(r['Results'][i]['Pedestrian'][0]['Face']['Features'])
                                    feature = feature.replace('\n','')
                                    self.id += 1
                                    f.write(str(self.id) + ' '
                                            + name1[random.randint(0, len(name1) - 1)] 
                                            + name2[random.randint(0, len(name2) - 1)] + ' '
                                            + conf['uri_header'] + batch_list[i][batch_list[i].index('/'):] + ' '
                                            + feature + '\n')
                                else:
                                    self.Error(batch_list[i])
                        else: 
                            self.Error(batch_list)
                        batch_list = []

#            else:
#                print "before", self.name, "----"
#                if conf['mode'] == 0:
#                    if len(batch_list) >= 1:
#                        r = self.Search(batch_list)
#                        if r: 
#                            if len(r['Result']['Pedestrian']) > 0 and r['Result']['Pedestrian'][0].has_key('Face'):
#                                feature = str(r['Result']['Pedestrian'][0]['Face']['Features'])
#                                feature = feature.replace('\n','')
#                                self.id += 1
#                                f.write(str(self.id) + ' ' 
#                                        + name1[random.randint(0, len(name1) - 1)] 
#                                        + name2[random.randint(0, len(name2) - 1)] + ' '
#                                        + conf['uri_header'] + batch_list[0][batch_list[0].index('/'):] + ' '
#                                        + feature + '\n')
#                            else:
#                                self.Error(batch_list)
#                        else:
#                            self.Error(batch_list)
#                        batch_list = []
#                else:
#                    if len(batch_list):
#                        r = self.Search(batch_list)
#                        if r:
#                            for i in range(0, len(batch_list)):
#                                if len(r['Results'][i]['Pedestrian']) > 0 and r['Results'][i]['Pedestrian'][0].has_key('Face'):
#                                    feature = str(r['Results'][i]['Pedestrian'][0]['Face']['Features'])
#                                    feature = feature.replace('\n','')
#                                    self.id += 1
#                                    f.write(str(self.id) + ' '
#                                            + name1[random.randint(0, len(name1) - 1)] 
#                                            + name2[random.randint(0, len(name2) - 1)] + ' '
#                                            + conf['uri_header'] + batch_list[i][batch_list[i].index('/'):] + ' '
#                                            + feature + '\n')
#                                else:
#                                    self.Error(batch_list[i])
#                    else:
#                        self.Error(batch_list)
#                    batch_list = []
#                print "end", self.name, "----"


#    def batch_run(self, root_path, batch_num):
#        batch_list = []
#        for sub_dir_name in os.listdir(root_path):
#            temp_path = "%s/%s" %(root_path, sub_dir_name)
#            #print "temp_path:%s" %(temp_path)
#            if re.search("^\.", sub_dir_name) != None:
#                #print "not deal it."
#                continue
#            if os.path.isfile(temp_path):
##                if re.search("\.jpg", temp_path) == None:
##                    continue
#                #print "-------------------"
#                #print temp_path
#                batch_list.append(temp_path)
#                if len(batch_list) >= batch_num:
#                    self.Search(batch_list)
#                    batch_list = []
#            elif os.path.isdir(temp_path):
#                #print "in iter..."
#                #self.batch_run(temp_path)
#                self.batch_run(temp_path, batch_num)
#        if len(batch_list) != 0:
#            self.Search(batch_list)
#            batch_list = []

    def run(self):
        while conf["onePass"] != 2:
            try:
                if conf['mode'] == 0:
                    self.batch_run(1)
                    if conf["onePass"] == 1:
                        conf["onePass"] = 2
                elif conf['mode'] == 1:
                    self.batch_run(conf['batch_num'])
                    if conf["onePass"] == 1:
                        conf["onePass"] = 2
            except:
                pass


class StatThread(threading.Thread) :
    def __init__(self) :
        threading.Thread.__init__(self)
        self.setDaemon(True)
        self.cycleCount = 0
        self.logger = logging.getLogger("StatLogger")
        #mika:make log name with requestID
        log_name = "./log/stat.restful.log." + str(conf["requestID"])
        print "log_name:%s" %(log_name)
        handler = logging.handlers.RotatingFileHandler(log_name,
                maxBytes = 20971520, backupCount = 5)
        self.logger.addHandler(handler)
        self.logger.setLevel(logging.DEBUG)
        self.logger.info(
                "[[time.time:%s]]" % str(int(time.time())))
        self.logger.info(
                "[[loadtest start at %s]]" % str(datetime.datetime.now()))
        self.logger.info("Timeout Threshold: %dms", conf["timeout"])
        self.logger.info("thread_num: %d", conf["thread_num"])
    
    def SnapShot(self) :
        # save stats
        self.timeDist = stat["timeDist"][:]
        self.carNumDist = stat["carNumDist"][:]
        self.requestCount = stat["requestCount"]
        self.timeoutCount = stat["timeoutCount"]
        self.requestTime = stat["requestTime"]
        self.timeoutTime = stat["timeoutTime"]
        self.httpCodeDist = stat["httpCodeDist"][:]
        self.statusCodeDist = stat["statusCodeDist"][:]
        self.httpErrorCount = stat["httpErrorCount"]
        self.httpErrorTime = stat["httpErrorTime"]
        self.errorCount = stat["errorCount"]
        self.errorTime = stat["errorTime"]
        self.carCount = stat["carCount"]
        self.plateCount = stat["plateCount"]
        self.colorCount = stat["colorCount"]

            
        if self.requestCount != 0:
            stat["max_qps"] = max(self.requestCount*1.0/conf["interval"], stat["max_qps"])
            stat["min_qps"] = min(self.requestCount*1.0/conf["interval"], stat["min_qps"])

        # reset stats
        stat["timeDist"] = [0] * (len(timeBound) + 1)
        stat["carNumDist"] = [0] * (len(carNumBound) + 1)
        stat["requestCount"] = 0
        stat["timeoutCount"] = 0
        stat["requestTime"] = 0.0
        stat["timeoutTime"] = 0.0
        stat["httpCodeDist"] = [0] * 1000
        stat["statusCodeDist"] = [0] * 1000
        stat["httpErrorCount"] = 0
        stat["HTTPErrorTime"] =0.0
        stat["errorCount"] = 0
        stat["errorTime"] = 0.0
        stat["carCount"] = 0
        stat["plateCount"] = 0
        stat["colorCount"] = 0


        # count all
        stat["timeDistAll"] = map(operator.add,
                stat["timeDistAll"], self.timeDist)
        stat["carNumDistAll"] = map(operator.add,
                stat["carNumDistAll"], self.carNumDist)
        stat["requestCountAll"] += self.requestCount
        stat["timeoutCountAll"] += self.timeoutCount
        stat["requestTimeAll"] += self.requestTime
        stat["timeoutTimeAll"] += self.timeoutTime
        stat["httpCodeDistAll"] = map(operator.add,
                stat["httpCodeDistAll"], self.httpCodeDist)
        stat["statusCodeDistAll"] = map(operator.add,
                stat["statusCodeDistAll"], self.statusCodeDist)
        stat["httpErrorCountAll"] += self.httpErrorCount
        stat["httpErrorTimeAll"] += self.httpErrorTime
        stat["errorCountAll"] += self.errorCount
        stat["errorTimeAll"] += self.errorTime
        stat["carCountAll"] += self.carCount
        stat["plateCountAll"] += self.plateCount
        stat["colorCountAll"] += self.colorCount


    def StatInfo(self, requestCount, timeoutCount, requestTime,
            timeoutTime, timeDist, elapse,
            httpCodeDist, errorCount, errorTime, httpErrorCount, HTTPErrorTime,
            statusCodeDist, carNumDist, carCount, plateCount, colorCount
            ) :
        elapse *= 1.0
        effectiveCount = requestCount  - errorCount - httpErrorCount;
        effectiveTime = requestTime -  errorTime - HTTPErrorTime;
        if elapse == 0:
            avgTimeoutCount = 0
            avgRequestCount = 0
            avgEffectiveCount = 0
            avgErrorCount = 0
            avgHttpErrorCount = 0
        else:
            avgTimeoutCount = timeoutCount / elapse
            avgRequestCount = requestCount / elapse
            avgEffectiveCount = effectiveCount / elapse
            avgErrorCount = errorCount / elapse
            avgHttpErrorCount = httpErrorCount / elapse

        if requestCount == 0:
            avgRequestTime = 0
        else:
            avgRequestTime = requestTime / requestCount

        if effectiveCount == 0:
            avgEffectiveTime = 0
        else:
            avgEffectiveTime = effectiveTime / effectiveCount

        throughput = 0
        time_1w = 0
        car_per_p = 0
        if conf['mode'] == 0:
            throughput = int(avgEffectiveCount * 86400)
            if avgEffectiveCount != 0:
                time_1w = 10000 / (avgEffectiveCount)
            if effectiveCount != 0:
                car_per_p = carCount*1.0/ effectiveCount
        elif conf['mode'] == 1:
            throughput = int(avgEffectiveCount * conf['batch_num'] * 86400)
            if avgEffectiveCount != 0:
                time_1w = 10000 / (avgEffectiveCount * conf['batch_num'])
            if effectiveCount != 0:
                car_per_p = carCount*1.0/(effectiveCount*conf['batch_num'])
        color_per_p = 0.0
        plate_per_p = 0.0
        if carCount != 0:
            color_per_p = colorCount*1.0/carCount
            plate_per_p = plateCount*1.0/carCount

        statInfo = "### Search time:%d, ErrorCount:%d, HttpErrorCount:%d,\n"\
                   "### error image count:%d,\n"\
                   "### timeoutCount:%d, avgTimeoutCount:%.2f/s,\n" \
                   "### avgQPS/avgEffectiveQPS:%.2f/%.2f/s,\n" \
                   "### avgRequestTime/avgEffectiveRequestTime:%.2fms/%.2fms,\n"\
                   "### maxQPS/minQPS:%.2f/%.2f,\n"\
                   "### maxReqestTime/minRequestTime:%.2fms/%.2fms,\n"\
                   "### Throughput per Day:%d,\n"\
                   "### Timecost per 1W::%.2fs,\n"\
                   "### colorCount:%d,%.4f plateCount:%d,%.4f carCount:%d,\n"\
                   "### car per photo:%.2f,\n"\
                   "### elapse:%ds\n" % (
                        requestCount, errorCount, httpErrorCount, 
                        stat['errorImageCount'],
                        timeoutCount,
                        avgTimeoutCount, avgRequestCount, avgEffectiveCount,
                        avgRequestTime, avgEffectiveTime,
                        stat["max_qps"], stat["min_qps"],
                        stat["max_time"], stat["min_time"],
                        throughput,
                        time_1w,
                        colorCount, color_per_p, plateCount, plate_per_p, carCount,
                        car_per_p,
                        int(elapse))

        timeDistStr = [];
        timeDistStr.append("Time distro:")
        for i in range(len(timeDist)) :
            if i == 0 :
                timeDistStr.append("  0   - %-3d ms: %d" % (timeBound[i],
                    timeDist[i]))
            elif i == len(timeBound) :
                timeDistStr.append("  >  %-3d ms  : %d" % (timeBound[i - 1],
                    timeDist[i]))
            else :
                timeDistStr.append("  %-3d - %-3d ms: %d" % (timeBound[i - 1],
                    timeBound[i], timeDist[i]))


        carNumDistStr = [];
        carNumDistStr.append("Car Num distro:")
        for i in range(len(carNumDist)) :
            if i == 0 :
                carNumDistStr.append("  [ 0   - %-3d): %d" % (carNumBound[i],
                    carNumDist[i]))
            elif i == len(carNumBound) :
                carNumDistStr.append("  >  %-3d: %d" % (carNumBound[i - 1], 
                    carNumDist[i]))
            else :
                carNumDistStr.append("  [ %-3d - %-3d): %d" % (carNumBound[i - 1],
                    carNumBound[i], carNumDist[i]))


        resultDistStr = [];

        httpCodeDistStr = [];
        httpCodeDistStr.append("Http Code distro:")
        for i in range(len(httpCodeDist)) :
            if httpCodeDist[i] == 0 :
                continue;
            httpCodeDistStr.append("  %s : %d" % (str(i), httpCodeDist[i]))


        statusCodeDistStr = [];
        statusCodeDistStr.append("DeepV Status Code distro:")
        for i in range(len(statusCodeDist)) :
            if statusCodeDist[i] == 0 :
                continue;
            statusCodeDistStr.append("  %s : %d" % (str(i), statusCodeDist[i]))

        for i in range(
                max(len(timeDistStr), len(resultDistStr), len(httpCodeDistStr), \
                    len(statusCodeDistStr), len(carNumDistStr))) :
            str1 = str2 = str3 = str4 = str5 = ""
            if i < len(timeDistStr) : str1 = timeDistStr[i]
            if i < len(resultDistStr) : str2 = resultDistStr[i]
            # added by mika
            if i < len(httpCodeDistStr) : str3 = httpCodeDistStr[i]
            if i < len(statusCodeDistStr) : str4 = statusCodeDistStr[i]
            if i < len(carNumDistStr) : str5 = carNumDistStr[i]
            statInfo += "%-25s %-22s %-0s %-25s %-28s\n" % (str1, str5, str2, str3, str4)
            #statInfo += "%-25s %-26s %-25s\n" % (str1, str2, str3)

        return statInfo


    def run(self) :
        while conf["onePass"] != 2 :
            time.sleep(conf["interval"])
            self.cycleCount += 1
            self.SnapShot()
            statInfo = "#" * 26 + str(datetime.datetime.now()) + "#" * 26 + "\n"
            if conf["verbose"] :
                statInfo += "verbose:\n"
                statInfo += self.StatInfo(self.requestCount, 
                        self.timeoutCount, self.requestTime, 
                        self.timeoutTime, self.timeDist,
                        conf["interval"], self.httpCodeDist,
                        self.errorCount, self.errorTime, self.httpErrorCount,
                        self.httpErrorTime, self.statusCodeDist, self.carNumDist, 
                        self.carCount, self.plateCount, self.colorCount)
                statInfo += "=-" * 38 + "\n"


            statInfo += self.StatInfo(
                    stat["requestCountAll"], 
                    stat["timeoutCountAll"], stat["requestTimeAll"],
                    stat["timeoutTimeAll"],
                    stat["timeDistAll"],
                    conf["interval"] * self.cycleCount,stat["httpCodeDistAll"],
                    stat["errorCountAll"],stat["errorTimeAll"],
                    stat["httpErrorCountAll"],stat["httpErrorTimeAll"],
                    stat["statusCodeDistAll"], stat["carNumDistAll"],
                    stat["carCountAll"], stat["plateCountAll"], stat["colorCountAll"])


            print statInfo
            self.logger.info(statInfo)
        os.kill(os.getpid(), signal.SIGKILL)

def quitTest(signum, frame) :
    print "loadtest quit"
    sys.exit(0)

processImages = []

def read_image(root_path):
    for sub_dir_name in os.listdir(root_path):
        temp_path = "%s/%s" %(root_path, sub_dir_name)
        if re.search("^\.", sub_dir_name) != None:
            #print "not deal it."
            continue
        if os.path.isfile(temp_path):
            if re.search("\.jpg", temp_path) == None:
                continue
            while fileList.full():
                time.sleep(1)
            else:
                if len(processImages):
                    for i in range(len(processImages)):
                        if temp_path == processImages[i]:
                            fileList.put(temp_path)
                            del processImages[i]
                            break

                else:
                    fileList.put(temp_path)
        elif os.path.isdir(temp_path):
            read_image(temp_path)

#do load test
def LoadTest() :
    testThreads = []
    if os.path.exists(conf['feature_file']) == False: 
        os.mkdir(conf['feature_file'])

    for i in range(conf["thread_num"]) :
        thrd = QueryThread(conf['photo_path'], str(i + 1))
        testThreads.append(thrd)
        thrd.start()

    try:
        statThread = StatThread()
        statThread.start()
        if os.path.exists(conf['finished_file']):
            if os.path.exists(conf['error_list']):
                os.rename(conf['error_list'], "error.list.bak")
                with open("error.list.bak") as f:
                    line = f.readline()
                    while line:
                        while fileList.full():
                            time.sleep(1)
                        else:
                            filename = line.replace('\n','')
                            fileList.put(filename)
                            line = f.readline()
                os.remove("error.list.bak")
        else: 
            for i in range(conf['thread_num']):
                if os.path.exists('log/' + str(i + 1)):
                    with open('log/' + str(i + 1), 'r') as f:
                        processImages.extend(f.readlines())
            
            for i in range(len(processImages)):
                processImages[i] = processImages[i].replace("\n", "")

            read_image(conf['photo_path'])

    except:
        print "load test error.............."
        sys.stdout = open('log/error.log.' + str(conf["requestID"]), 'a')
        print  sys.exc_info()[0],sys.exc_info()[1]
        sys.stdout = sys.__stdout__
        sys.exit(0)

    if conf["duration"] != 0 :
        signal.signal(signal.SIGALRM, quitTest)
        signal.alarm(conf["duration"] + 1)

    while fileList.empty() == False:
        time.sleep(1)
    else:
        for t in testThreads:
            t.STOP()

    while True:
        all_die = True
        for t in testThreads:
            if t.is_alive():
                time.sleep(1)
                all_dir = False
        if all_die == True:
            break
#    for t in testThreads:
#        t._Thread__stop()
#
#    for i in range(conf["thread_num"]):
#        feature_file = "feature",   # feature files
#        name = conf['feature_file'] + "/" + str(i + 1) + ".txt"
#        #status, lineCnt = commands.getstatusoutput("cat " + name + " | wc -l")
#        status, output = commands.getstatusoutput("awk '{$1=NR} 1' " + name + " 1<> " + name)

    if os.path.exists(conf['finished_file']) == False:
        f = open(conf['finished_file'], 'w')
        f.close()

    if os.path.exists(conf['error_list']) == False:
        f = open(conf['error_list'], "w")
        f.close()

    sys.exit(0)

if __name__ == "__main__":
    LoadTest()
