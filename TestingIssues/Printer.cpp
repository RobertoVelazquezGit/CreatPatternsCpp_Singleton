#include "Printer.h"
#include "LocalPrinter.h"
#include "MockPrinter.h"

Printer& Printer::GetInstance(const std::string& key) {
	if (key == "local") {
		// Assinging reference of derived class to a referencie of base class
		return LocalPrinter::GetInstance();
	}
	if (key == "mock") {
		return MockPrinter::GetInstance();
	}
	throw std::invalid_argument("Invalid printer type");
}

