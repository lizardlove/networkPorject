#include "XConditionVariable.h"
#include "XMutex.h"
#include <iostream>
using namespace std;

XConditionVariable::XConditionVariable()
{
	int  r = pthread_cond_init(&m_ConditionVariable, 0);
	if(r != 0)
	{
        cout << "In XConditionVariable::XConditionVariable(), pthread_cond_init error" << r << endl;
		throw "In XConditionVariable::XConditionVariable(), pthread_cond_init error";
	}
}

XConditionVariable::~XConditionVariable()
{
	int r = pthread_cond_destroy(&m_ConditionVariable);
	if(r != 0)
	{
        cout << "In XConditionVariable::~XConditionVariable(), pthread_cond_destroy error" << r << endl;
		throw "In XConditionVariable::~XConditionVariable(), pthread_cond_destroy error";
	}
}

bool XConditionVariable::Wait(XMutex *pMutex)
{
	if(pMutex == NULL)
		return false;

	int r = pthread_cond_wait(&m_ConditionVariable, &(pMutex->m_Mutex));
	if(r != 0)
	{
        cout << "In XConditionVariable::Wait, pthread_cond_wait error" << r << endl;
		return false;
	}
	else
	{
		return true;
	}
}

bool XConditionVariable::Wakeup()
{
	int r = pthread_cond_signal(&m_ConditionVariable);
	if(r != 0)
	{
        cout << "In XConditionVariable::Wakeup, pthread_cond_signal error" << r << endl;
		return false;
	}
	else
	{
		return true;
	}
}

bool XConditionVariable::WakeupAll()
{
	int r = pthread_cond_broadcast(&m_ConditionVariable);
	if(r != 0)
	{
        cout << "In XConditionVariable::WakeupAll, pthread_cond_broadcast error" << r << endl;
		return false;
	}
	else
	{
		return true;
	}
}