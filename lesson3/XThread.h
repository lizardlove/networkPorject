#ifndef XTHREAD_H
#define XTHREAD_H

#include <pthread.h>
#include "XExecutive.h"

class XThread : public XExecutive
{
public:
	explicit XThread(XExecutiveFunctionProvider *pExecutiveFunctionProvider);
	virtual ~XThread();

	virtual bool Run(void *pContext = 0);

	virtual bool WaitForDeath();

private:
	static void* StartFunctionOfThread(void *pContext);

private:
	void *m_pContext;
	pthread_t m_ThreadID; 
};

#endif