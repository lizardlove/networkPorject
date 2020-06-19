#include "XThread.h"
#include "XExecutiveFunctionProvider.h"
#include <iostream>
using namespace std;

XThread::XThread(XExecutiveFunctionProvider *pExecutiveFunctionProvider) : XExecutive(pExecutiveFunctionProvider)
{
	m_pContext = 0;
}

XThread::~XThread()
{
}

bool XThread::Run(void *pContext)
{	
	m_pContext = pContext;

	int r = pthread_create(&m_ThreadID, 0, StartFunctionOfThread, this);
	if(r != 0)
	{
        cout << "In XThread::Run(), pthread_create error " << r << endl;
		return false;
	}

	return true;
}

void* XThread::StartFunctionOfThread(void *pThis)
{	
	XThread *pThreadThis = (XThread *)pThis;

	pThreadThis->m_pExecutiveFunctionProvider->RunExecutiveFunction(pThreadThis->m_pContext);

	return 0;
}

bool XThread::WaitForDeath()
{
	int r = pthread_join(m_ThreadID, 0);
	if(r != 0)
	{
        cout << "In XThread::WaitForDeath(), pthread_join error " << r << endl;
		return false;
	}

	return true;
}