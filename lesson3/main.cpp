#include <iostream>
#include <unistd.h>
#include "XThreadPool.h"
#include "XThread.h"
#include "XExecutiveFunctionProvider.h"
#include "XEvent.h"

using namespace std;

int x = 1;

class Consumer : public XExecutiveFunctionProvider
{
    public:
        Consumer(){}

        virtual ~Consumer(){}

        virtual bool RunExecutiveFunction(void *pContext)
        {
            XEvent *pEvent = (XEvent *)pContext;
            m_num = 0;
            while(m_num< 100) {
                if (m_num < x) {
                    m_num++;
                    cout << "Consumer eat " << m_num << endl;
                } else {
                    cout << m_num << "There isn't data to eat." << endl;
                    pEvent->Wait();
                }
            }

            return true;
        }
    private: 
        int m_num;
};

class Producter: public XExecutiveFunctionProvider 
{
    public:

        Producter(){}

        virtual ~Producter(){}

        virtual bool RunExecutiveFunction(void *pContext)
        {
            XEvent *pEvent = (XEvent *)pContext;
            while(x < 100) {
                x = x + 1;
                cout << "producter new " << x << endl;
                pEvent->Set();
            }


            return true;
        }
};

int main()
{
    int i = 0;
    XEvent *pEvent = new XEvent;
    XThreadPool *pool = new XThreadPool(10);
    
    XExecutiveFunctionProvider *consumerFunction = new Consumer();
    XExecutiveFunctionProvider *producterFunction = new Producter();
    //不使用线程池
    XExecutive *consumerThread = new XThread(consumerFunction);
    XExecutive *producterThread = new XThread(producterFunction);
    producterThread->Run((void *)pEvent);
    consumerThread->Run((void *)pEvent);

    producterThread->WaitForDeath();
    consumerThread->WaitForDeath();

    //使用线程池-未完成
    // pool->addTask(consumerFunction);
    // pool->addTask(producterFunction);



    cout << "in main thread " << x << endl;

    delete consumerThread;
    delete producterThread;
    delete consumerFunction;
    delete producterFunction;
    delete pEvent;

    return 0;
}