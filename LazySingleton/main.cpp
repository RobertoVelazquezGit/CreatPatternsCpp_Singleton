#include "Logger.h"
#include <thread>
#include <chrono>

void OpenConnection() {
	Logger &lg = Logger::Instance();
	lg.WriteLog("Attempting to open a connection");
}
int main() {
#if ENABLE_FEATURE == 4 || ENABLE_FEATURE == 5 || ENABLE_FEATURE == 6
	std::thread t1{ []() {
		Logger& lg = Logger::Instance();
		lg.WriteLog("Thread 1 has started");
	} };
	std::thread t2{ []() {
		Logger& lg = Logger::Instance();
		lg.WriteLog("Thread 2 has started");
	} };
	std::this_thread::sleep_for(std::chrono::seconds(1));
	t1.join();
	t2.join();
#else
	Logger& lg = Logger::Instance();
	lg.SetTag("192.168.1.101");
	lg.WriteLog("Application has started");
	OpenConnection();
	lg.WriteLog("Application is shutting down");
#endif
}
