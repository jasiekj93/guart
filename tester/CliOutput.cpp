#include "CliOutput.hpp"
// #include <stdio.h>
#include <iostream>

using namespace guart;

Output& CliOutput::operator<<(const std::string_view str)
{
    // printf("%s" , str.data());
    std::cout << str;
    return *this;
}

Output& CliOutput::operator<<(char c)
{
    // printf("%c", c);
    std::cout << c;
    return *this;
}

void CliOutput::flush()
{
    std::cout.flush();
    // fflush(stdout);
}