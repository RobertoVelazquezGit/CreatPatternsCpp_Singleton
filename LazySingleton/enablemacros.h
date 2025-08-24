#pragma once

/*
* ENABLE_MACRO_FEATURE
* 1: Original eager example without MockPrinter
* 2: Addes mockPrinter
* 3: Lazy instance with smart pointer
* 4: Lazy instance with raw pointer, threading and mutex
* 5: Meyer's singleton
* 6: Call once
*/
#define ENABLE_FEATURE 6