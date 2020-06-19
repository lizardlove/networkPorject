#ifndef XConditionVariable_H
#define XConditionVariable_H

#include <pthread.h>
#include "XMutex.h"

class XMutex;

class XConditionVariable
{
public:
	/*
	构造函数和析构函数出错时，会抛出字符串类型异常
	*/
	XConditionVariable();
	virtual ~XConditionVariable();

	bool Wait(XMutex *pMutex);
	bool Wakeup();
	bool WakeupAll();

private:
	XConditionVariable(const XConditionVariable&);
	XConditionVariable& operator=(const XConditionVariable&);

private:
	pthread_cond_t m_ConditionVariable;
};

#endif