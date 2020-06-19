#include "XCriticalSection.h"
#include "XMutex.h"
#include <iostream>
using namespace std;

XCriticalSection::XCriticalSection(XMutex *pMutex)
{
	if(pMutex == 0)
	{
        cout << "In XCriticalSection::XCriticalSection(), pMutex == 0" << endl;
		throw "In XCriticalSection::XCriticalSection(), pMutex == 0";
	}
	
	m_pMutex = pMutex;

	bool s = m_pMutex->Lock();
	if(!s)
	{
        cout << "In XCriticalSection::XCriticalSection(), m_pMutex->Lock error" << endl;
		throw "In XCriticalSection::XCriticalSection(), m_pMutex->Lock error";
	}
}

XCriticalSection::~XCriticalSection()
{
	bool s = m_pMutex->Unlock();
	if(!s)
	{
        cout << "In XCriticalSection::~XCriticalSection(), m_pMutex->Unlock error" << endl;
		throw "In XCriticalSection::~XCriticalSection(), m_pMutex->Unlock error";
	}
}