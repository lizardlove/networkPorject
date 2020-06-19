#include "XExecutive.h"
#include "XExecutiveFunctionProvider.h"

XExecutive::XExecutive(XExecutiveFunctionProvider *pExecutiveFunctionProvider)
{
	if(pExecutiveFunctionProvider == 0)
		throw "In XExecutive::CLExecutive(), pExecutiveFunctionProvider error";

	m_pExecutiveFunctionProvider = pExecutiveFunctionProvider;
}

XExecutive::~XExecutive()
{
}