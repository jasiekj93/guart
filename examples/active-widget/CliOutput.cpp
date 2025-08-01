#include "CliOutput.hpp"
// #include <stdio.h>
#include <iostream>

using namespace guart;

Output& CliOutput::operator<<(const std::string_view str)
{
    std::cout << str;
    return *this;
}

Output& CliOutput::operator<<(char c)
{
    std::cout << c;
    return *this;
}

void CliOutput::flush()
{
    std::cout.flush();
}