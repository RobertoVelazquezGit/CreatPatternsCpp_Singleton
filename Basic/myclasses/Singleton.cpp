#include "Singleton.h"
#include <iostream>
Singleton Singleton::m_Instance;
Singleton& Singleton::Instance()
{
	return m_Instance;
}

void Singleton::MethodA()
{
	std::cout << "MethodA ..." << std::endl;
}

void Singleton::MethodB()
{
}
