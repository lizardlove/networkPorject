#ifndef XEVENT_H
#define XEVENT_H
#include "XMutex.h"
#include "XConditionVariable.h"

/*
 创建一个初始无信号，自动重置信号的信号（用于唤醒一个 等待线程）
*/
class XEvent
{
public: 
	/*
	构造函数和析构函数出错时，会抛出字符串类型异常
	*/
	XEvent( );
	virtual ~XEvent();

public: 
	bool Set();

	bool Wait();

private:
	XEvent(const XEvent&);
	XEvent& operator=(const XEvent&);

private:
	XMutex m_Mutex;
	XConditionVariable m_Cond;
	int m_Flag;
};

#endif