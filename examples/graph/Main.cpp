/**
 * @file Main.cpp
 * @author Adrian Szczepanski
 * @date 2025-06-30
 */

#include <iostream>

#include <libguart/Widgets.hpp>

#include "CliOutput.hpp"
#include "Serial.hpp"
#include "TerminalInput.hpp"

using namespace guart;

int main(int argc, char* argv[])
{
    CliOutput output;
    // Serial output("/dev/ttyUSB1");

    Screen screen(output);

    auto graph = std::make_shared<widget::ScatterPlot>(Point{30, 6}, Dimensions{20, 10}, true);
    graph->setTitle("Sample ScatterPlot");
    graph->setXTitle("X");
    graph->setYTitle("Y");
    graph->setItems({{0, 0}, {1, 1}, {2, 1}, {2, 3}, {3, 3}});

    screen.addWidget(graph);
    screen.invalidate();
    TerminalInput termInput;
    
    if (not termInput.initialize())
    {
        std::cerr << "Failed to initialize terminal input" << std::endl;
        return 1;
    }

    while(true)
    {
        std::string key = termInput.getSpecialKey();

        if(not screen.processInput(key))
            break; // Exit the application
    }

    return 0;
}
