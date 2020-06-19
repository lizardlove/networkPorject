#ifndef XCriticalSection_H
#define XCriticalSection_H
#include "XMutex.h"

class XMutex;

class XCriticalSection
{
public:
	/*
	出错时构造函数和析构函数将会抛出字符串类型异常
	*/
	XCriticalSection(XMutex *pMutex);
	virtual ~XCriticalSection();

private:
	XCriticalSection(const XCriticalSection&);
	XCriticalSection& operator=(const XCriticalSection&);

private:
	XMutex *m_pMutex;
};

#endif