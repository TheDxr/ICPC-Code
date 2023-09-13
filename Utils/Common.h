#pragma once

#include "DataStructure.h"
#include "Test/Print.h"
#include "Test/TestData.h"
#include "Test/UnitTest.h"

namespace Utils
{
bool isSpace(char c) { return (c == ' '); }
bool isNum(char c) { return ('0' <= c && c <= '9'); }
bool isLetter(char c) { return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')); }
bool isOperator(char c) { return !isSpace(c) && !isNum(c) && !isLetter(c); }


#define BIND_FILE_TO_CIN std::ifstream cin("../input.txt");
#define BIND_FILE_TO_COUT std::ofstream cout("../output.txt");
} // namespace util