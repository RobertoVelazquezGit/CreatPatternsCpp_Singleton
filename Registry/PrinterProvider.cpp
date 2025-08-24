#include "PrinterProvider.h"
#include <iostream>

void PrinterProvider::RegisterPrinter(const std::string& key, Printer* p) {
	std::lock_guard lock{ m_mtx };
	if (auto it = m_Printers.find(key); it == end(m_Printers)) {  // if with intializer
		m_Printers[key] = p;
	}
	else {
		std::cout << "Already registered\n";
	}
}

Printer* PrinterProvider::GetPrinterPtr(const std::string& key) {
	std::lock_guard lock{ m_mtx };
	if (auto it = m_Printers.find(key); it != end(m_Printers)) {
		return m_Printers[key];
	}
	return nullptr;
}

Printer& PrinterProvider::GetPrinterRef(const std::string& key) {
	// Mistake, it causes a dead lock std::lock_guard lock{ m_mtx };  
	auto p = GetPrinterPtr(key);  // Inside GetPrinterPtr the mutex is taken again
	if (p) return *p;
	throw std::runtime_error{ "No such printer" };
}
