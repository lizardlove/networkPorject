#ifndef XEXECUTIVEFUNCTIONPROVIDER_H
#define XEXECUTIVEFUNCTIONPROVIDER_H

/*
XExecutiveFunctionProvider类封装了执行体具体的业务功能
*/
class XExecutiveFunctionProvider
{
public:
	XExecutiveFunctionProvider();
	virtual ~XExecutiveFunctionProvider();

public:
	virtual bool RunExecutiveFunction(void* pContext) = 0;

private:
	XExecutiveFunctionProvider(const XExecutiveFunctionProvider&);
	XExecutiveFunctionProvider& operator=(const XExecutiveFunctionProvider&);
};

#endif