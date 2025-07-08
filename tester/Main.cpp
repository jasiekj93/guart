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
#include "ButtonObserver.hpp"

using namespace guart;

int main(int argc, char* argv[])
{
    CliOutput output;
    // Serial output("/dev/ttyUSB1");

    Screen screen(output);
    ButtonObserver buttonObserver(&screen); // Initialize with nullptr, will set later

    auto window = std::make_shared<widget::Window>(Point{10, 10}, Dimensions{30, 10});
    auto window2 = std::make_shared<widget::Window>(Point{0, 1}, Dimensions{30, 2});
    screen.addWidget(window2);
    screen.addWidget(window);

    auto label = std::make_shared<widget::Label>(Point{0, 0}, "Hello World!");
    std::vector<std::string_view> buttonBoxButtons{ "Button1", "Button2" };
    std::vector<std::string_view> buttonBoxButtons2{ "Siema", "Mordo" };
    auto buttonBox = std::make_shared<widget::ButtonBox>(Point{0, 2}, Dimensions{20, 1}, buttonBoxButtons);
    auto buttonBox2 = std::make_shared<widget::ButtonBox>(Point{1, 4}, Dimensions{20, 1}, buttonBoxButtons2);

    window->addWidget(label);
    window->addWidget(buttonBox);
    window->setTitle("Test Window");
    window2->setTitle("Second Window");
    buttonBox2->setTitle("Button Box 2");
    buttonBox2->setObserver(&buttonObserver);
    buttonBox->setObserver(&buttonObserver);
    screen.addWidget(buttonBox2);

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
