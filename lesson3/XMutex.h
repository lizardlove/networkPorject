#ifndef XMutex_H
#define XMutex_H

#include <pthread.h>

class XMutex
{
public:
	friend class XConditionVariable;

	/*
	构造函数和析构函数出错时，会抛出字符串类型异常
	*/
	XMutex();
	virtual ~XMutex();

	bool Lock();
	bool Unlock();

private:
	XMutex(const XMutex&);
	XMutex& operator=(const XMutex&);

private:
	pthread_mutex_t m_Mutex;
};

#endif