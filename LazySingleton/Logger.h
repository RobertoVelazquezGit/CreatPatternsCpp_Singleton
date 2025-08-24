#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <memory>
#include "enablemacros.h"
#include <mutex>

class Logger
{
	FILE* m_pStream;
	std::string m_Tag;
	Logger();
#if ENABLE_FEATURE == 1
	static Logger m_Instance;
#elif ENABLE_FEATURE == 2
	static Logger * m_pInstance;
#elif ENABLE_FEATURE == 3
	struct Deleter {
		void operator()(Logger* p) {
			delete p;
		}
	};
	// inline static needs c++17
	inline static std::unique_ptr<Logger, Deleter> m_pInstance{};
#elif ENABLE_FEATURE == 4
	static Logger* m_pInstance;
	static std::mutex m_Mtx;
#elif ENABLE_FEATURE == 6
	static Logger* m_pInstance;
	static std::once_flag initFlag;
#endif

public:
	Logger(const Logger&) = delete;
	Logger& operator =(const Logger&) = delete;
	static Logger& Instance();
	~Logger();
	void WriteLog(const char* pMessage);
	void SetTag(const char* pTag);
};

