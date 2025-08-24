
#include "enablemacros.h"

#if ENABLE_FEATURE == 1
#include "LocalPrinter.h"

void PrintSales() {
	Printer::GetInstance("local").Print("Sales data");
}

int main() {
	auto& p = Printer::GetInstance("local");
	p.Print("Printing data to local printer");
	PrintSales();
}

#elif ENABLE_FEATURE == 2
#include "Printer.h"
#include "MockPrinter.h"
#include <cassert>
#include <iostream>
#include "LocalPrinter.h"

void PrintSales() {
    Printer::GetInstance("local").Print("Sales data");
}

void TestPrintFunction() {
    // Calls the static MockPrinter::GetInstance();
    Printer& printer = Printer::GetInstance("mock");  
    printer.Print("Test data");

    MockPrinter& mockPrinter = MockPrinter::GetInstance();
    assert(mockPrinter.GetLastPrinted() == "Test data");
    std::cout << "Test passed!\n";
}

int main() {
    TestPrintFunction();

    auto& p = Printer::GetInstance("local");
    p.Print("Printing data to local printer");
    PrintSales();

    return 0;
}
#endif
