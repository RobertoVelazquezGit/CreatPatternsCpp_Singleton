#pragma once
#include "Printer.h"
#include <string>
#include <iostream>

class MockPrinter : public Printer {
    static MockPrinter m_Instance;
    std::string lastPrinted;
    MockPrinter() = default;
public:
    static MockPrinter& GetInstance();
    void Print(const std::string& data) override;
    const std::string& GetLastPrinted() const;
};
