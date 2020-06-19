#ifndef XTHREADPOOL_H
#define XTHREADPOOL_H

#include <pthread.h>
#include "XThread.h"

class XThreadPool
{
public:
	explicit XThreadPool(int size = 10);
	virtual ~XThreadPool();

	virtual bool createThreads();

	virtual bool addTask(XExecutiveFunctionProvider *task);
    virtual XExecutiveFunctionProvider* take();

private:
	XThread* threads;
    pthread_mutex_t mutex;
    pthread_cond_t condition;
};

#endif