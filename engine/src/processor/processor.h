/*
 * processor.h
 *
 *  Created on: Jan 4, 2016
 *      Author: chenzhen
 */

#ifndef PROCESSOR_H_
#define PROCESSOR_H_

#include "model/model.h"
namespace deepglint {
/**
 * the basic processor interface.
 */
class Processor {
public:
	Processor() :
			next_(NULL) {

	}
	virtual ~Processor() {

	}
	virtual void Update(Frame *frame) = 0;
	virtual void Update(FrameBatch *frameBatch) = 0;
	virtual Frame* operator()(Frame* f) ;
protected:
	Processor *next_;

	bool checkOperation(Frame *frame) {
		return false;
	}
};
}
#endif /* PROCESSOR_H_ */
