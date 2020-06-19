#ifndef XEXECUTIVE_H
#define XEXECUTIVE_H

class XExecutiveFunctionProvider;

/* 
CLExecutive类用于创建一个执行体
*/
class XExecutive
{
public:
	explicit XExecutive(XExecutiveFunctionProvider *pExecutiveFunctionProvider);
	virtual ~XExecutive();

	virtual bool Run(void *pContext = 0) = 0;

	virtual bool WaitForDeath() = 0;
	
protected:
	XExecutiveFunctionProvider *m_pExecutiveFunctionProvider;

private:
	XExecutive(const XExecutive&);
	XExecutive& operator=(const XExecutive&);
};

#endif