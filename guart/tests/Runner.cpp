/**
 * @file Runner.cpp
 * @author Adrian Szczepanski
 * @date 2025-06-30
 */

#include <CppUTest/CommandLineTestRunner.h>

int main(int argc, char* argv[])
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
