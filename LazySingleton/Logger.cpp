#include "Logger.h"
#include <iostream>
#include "enablemacros.h"

/*
* For classes's static variables:
* Static variables are created (call to constructor) before main, and 
* destroyed after main (call to destructor)
*/
#if ENABLE_FEATURE == 1
Logger Logger::m_Instance;
#elif ENABLE_FEATURE == 2
Logger* Logger::m_pInstance = nullptr; // nullptr for readability
#elif ENABLE_FEATURE == 4
Logger* Logger::m_pInstance;
std::mutex Logger::m_Mtx;
#elif ENABLE_FEATURE == 6
Logger* Logger::m_pInstance;
std::once_flag Logger::initFlag;
#endif

Logger::Logger() {
	std::cout << __FUNCSIG__ << std::endl;
	m_pStream = fopen("applog.txt", "w");
#if ENABLE_FEATURE == 2 || ENABLE_FEATURE == 4 || ENABLE_FEATURE == 6
	atexit([]() {
		delete m_pInstance;
		});
#endif
}

Logger& Logger::Instance() {
#if ENABLE_FEATURE == 1
	return m_Instance;
#elif ENABLE_FEATURE == 2
	if (m_pInstance == nullptr) {
		m_pInstance = new Logger{};
	}
	return *m_pInstance;
#elif ENABLE_FEATURE == 3
	if (m_pInstance == nullptr) {
		m_pInstance.reset(new Logger());
	}
	return *m_pInstance;
#elif ENABLE_FEATURE == 4
	// Double-checked Locking pattern
	if (m_pInstance == nullptr) {
		m_Mtx.lock();
		if (m_pInstance == nullptr) {
			m_pInstance = new Logger{};
		}
		m_Mtx.unlock();
	}
	else {
		uint32_t n = 0;
	}
	return *m_pInstance;
#elif ENABLE_FEATURE == 5
	// Meyer's singleton. Lazy initialization.
	// This initialization is thread safe from C++11 onwards
	static Logger m_Instance;
	return m_Instance;
#elif ENABLE_FEATURE == 6
	// call_once is thread safe
	std::call_once(initFlag, [](int) {
		m_pInstance = new Logger{};
		}, 5);  // 5 example of passing a parameter
	return *m_pInstance;
#endif
}

Logger::~Logger()
{
	std::cout << __FUNCSIG__ << std::endl;
	fclose(m_pStream);
}

void Logger::WriteLog(const char* pMessage)
{
	fprintf(m_pStream, "[%s] %s\n", m_Tag.c_str(), pMessage);
	fflush(m_pStream);
}

void Logger::SetTag(const char* pTag)
{
	m_Tag = pTag;
}
