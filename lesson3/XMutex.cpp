#include "XMutex.h"
#include <iostream>
using namespace std;

XMutex::XMutex()
{
	int  r = pthread_mutex_init(&m_Mutex, 0);
	cout << "create mutex" << endl;
	if(r != 0)
	{
        cout << "In XMutex::XMutex(), pthread_mutex_init error" << r << endl;
		throw "In XMutex::XMutex(), pthread_mutex_init error";
	}
}

XMutex::~XMutex()
{
	int r = pthread_mutex_destroy(&m_Mutex);
	if(r != 0)
	{
        cout << "In XMutex::~XMutex(), pthread_mutex_destroy error" << r << endl;
		throw "In XMutex::~XMutex(), pthread_mutex_destroy error";
	}
}

bool XMutex::Lock()
{
	int r = pthread_mutex_lock(&m_Mutex);
	if(r != 0)
	{
        cout << "In XMutex::Lock(), pthread_mutex_lock error" << r << endl;
		return false;
	}
	else
	{
		return true;
	}
}

bool XMutex::Unlock()
{
	int r = pthread_mutex_unlock(&m_Mutex);
	if(r != 0)
	{
        cout << "In XMutex::Unlock(), pthread_mutex_unlock error" << r << endl;
		return false;
	}
	else
	{
		return true;
	}
}