/**
 * @file Main.cpp
 * @author Adrian Szczepanski
 * @date 2025-06-30
 */

#include <iostream>

#include <libguart/Window.hpp>
#include <libguart/Screen.hpp>
#include <libguart/Label.hpp>

#include "CliOutput.hpp"
#include "Serial.hpp"

using namespace guart;

int main(int argc, char* argv[])
{
    CliOutput output;
    // Serial output("/dev/ttyUSB1");

    Screen screen(output);
    auto window = std::make_shared<Window>(Point{10, 10}, Dimensions{20, 1});
    auto window2 = std::make_shared<Window>(Point{0, 1}, Dimensions{30, 2});
    screen.addWidget(window2);
    screen.addWidget(window);

    // screen.invalidate();
    // window2->moveTo(Point{5, 5});
    // screen.invalidate();
    // window->moveTo(Point{40, 30});
    // window->resize(Dimensions{8, 6});
    auto label = std::make_shared<Label>(Point{0, 0}, "Hello World!");

    window->addWidget(label);
    window->setLabel("Test Window");
    window2->setLabel("Second Window");
    screen.invalidate();

    return 0;
}
