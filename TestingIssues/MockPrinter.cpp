#include "MockPrinter.h"

MockPrinter MockPrinter::m_Instance;

MockPrinter& MockPrinter::GetInstance() {
    return m_Instance;
}

void MockPrinter::Print(const std::string& data) {
    lastPrinted = data;
    std::cout << "[MOCKPRINTER] " << data << '\n';
}

const std::string& MockPrinter::GetLastPrinted() const {
    return lastPrinted;
}

