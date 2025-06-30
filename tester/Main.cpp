/**
 * @file Main.cpp
 * @author Adrian Szczepanski
 * @date 2025-06-30
 */

#include <iostream>

#include <libguart/Window.hpp>

using namespace guart;

int main(int argc, char* argv[])
{
    Window window({10, 10}, {60, 50});
    window.draw();

    return 0;
}
