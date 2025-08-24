#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>

#include "BaseSingleton.h"

class Logger : public BaseSingleton<Logger>
{
	FILE* m_pStream;
	std::string m_Tag;
	// Needs to be friend, otherwise it can not call internally the Logger() constructor
	// from Basesingleton::static T& Instance()
	friend class BaseSingleton<Logger>;
	Logger();
	~Logger();
public:
	Logger(const Logger&) = delete;
	Logger& operator =(const Logger&) = delete;
	void WriteLog(const char* pMessage);
	void SetTag(const char* pTag);
};


