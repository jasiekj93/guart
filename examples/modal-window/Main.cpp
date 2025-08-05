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

void createModal(Screen& screen)
{
    auto modalWindow = std::make_shared<widget::ModalWindow>(
        Point{5, 5}, Dimensions{30, 10}, "This is a modal window\nAlso checking if it works\nwith multiple lines.", 
        widget::ButtonBox::Buttons{"OK", "Cancel"});
    modalWindow->setTitle("Modal Window");
    modalWindow->setLabel("modalWindow");

    modalWindow->onAction = [&screen](Widget& widget, std::string_view action) {
        auto toast = std::make_shared<guart::widget::Toast>(guart::Point{20, 20}, "Button clicked: " + std::string(action));
        screen.addWidget(toast);
        screen.invalidate();
        toast->onDispose = [&widget](Widget& w, std::string_view) {
            widget.dispose();
        };
    };

    screen.addWidget(modalWindow);
}

int main(int argc, char* argv[])
{
    CliOutput output;
    // Serial output("/dev/ttyUSB1");

    Screen screen(output);

    auto window = std::make_shared<widget::Window>(Point{10, 10}, Dimensions{30, 10});
    window->setLabel("window");

    widget::ButtonBox::Buttons buttonBoxButtons{ "Button1" };
    auto buttonBox = std::make_shared<widget::ButtonBox>(Point{0, 2}, Dimensions{20, 1}, buttonBoxButtons);
    buttonBox->setLabel("buttonBox");

    auto buttonBox2 = std::make_shared<widget::ButtonBox>(Point{0, 5}, Dimensions{20, 1}, buttonBoxButtons);
    buttonBox2->setLabel("buttonBox2");

    buttonBox->onAction = [&screen](Widget& widget, std::string_view action) {
        createModal(screen);
        screen.invalidate();
    };

    window->addWidget(buttonBox);
    window->addWidget(buttonBox2);
    screen.addWidget(window);

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
