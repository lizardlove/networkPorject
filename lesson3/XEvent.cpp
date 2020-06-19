#include "XEvent.h"
#include "XCriticalSection.h"
#include <iostream>
using namespace std;

XEvent::XEvent()
{
	m_Flag = 0;
}

XEvent::~XEvent()
{
}

bool XEvent::Set()
{
	try
	{
		XCriticalSection cs(&m_Mutex);

		m_Flag = 1;
	}
	catch(const char *str)
	{
        cout << "In XEvent::Set(), exception arise" << endl;
		return false;
	}
	bool s = m_Cond.Wakeup();
	if(!s)
	{
        cout << "In XEvent::Set(), m_Cond.Wakeup error" << endl;
		return false;
	}

	return true;
}

bool XEvent::Wait()
{
	try
	{
		XCriticalSection cs(&m_Mutex);

		while(m_Flag == 0)
		{
			bool s = m_Cond.Wait(&m_Mutex);
			if(!s)
			{
                cout << "In XEvent::Wait(), m_Cond.Wait error" << endl;
				return false;
			}
			cout << "wait cond" << endl;
		}

		m_Flag = 0;
	}
	catch(const char* str)
	{
        cout << "In XEvent::Wait(), exception arise" << endl;
		return false;
	}
	
	return true;
}