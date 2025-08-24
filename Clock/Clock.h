#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
//Monostate
class Clock
{
	inline static int m_Hour;
	inline static int m_Minute;
	inline static int m_Second;
	static void CurrentTime();
	Clock();
public:
	static int GetHour();
	static int GetMinute();
	static int GetSecond();
	static std::string GetTimeString();
};

