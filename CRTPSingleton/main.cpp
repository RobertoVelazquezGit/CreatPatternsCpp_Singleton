
#include <iostream>
#include <thread>
#include "Logger.h"
#include "BaseSingleton.h"

class GameManager : public BaseSingleton<GameManager> {
private:
	// This is what the macro MAKE_SINGLETON does
	GameManager() = default;
	friend class BaseSingleton<GameManager>;
public:
	void LoadAssets() {

	}
	void Run() {

	}
};

int main() {

	//GameManager g2;  // Error: private constructor
	//GameManager g1();  // Most vexing, declaring a function 
	//g1();  // Error: calling de funtion, unresolved symbol
	GameManager& gm1 = GameManager::Instance();
	GameManager& gm2 = GameManager::Instance();
	gm1.LoadAssets();

	std::thread t1{ []() {
		Logger& lg = Logger::Instance();
		lg.WriteLog("Thread 1 has started");
	} };
	std::thread t2{ []() {
		Logger& lg = Logger::Instance();
		lg.WriteLog("Thread 2 has started");
	} };
	t1.join();
	t2.join();
}


