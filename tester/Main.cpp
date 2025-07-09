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
    // ButtonObserver buttonObserver(&screen); // Initialize with nullptr, will set later

    auto window = std::make_shared<widget::Window>(Point{10, 10}, Dimensions{30, 10});
    window->setLabel("window");
    auto window2 = std::make_shared<widget::Window>(Point{0, 1}, Dimensions{30, 2});
    window2->setLabel("window2");
    screen.addWidget(window2);
    screen.addWidget(window);

    auto label = std::make_shared<widget::Label>(Point{0, 0}, "Hello World!");
    label->setLabel("label");
    widget::ButtonBox::Buttons buttonBoxButtons{ "Button1", "Button2" };
    widget::ButtonBox::Buttons buttonBoxButtons2{ "Siema", "Mordo" };
    auto buttonBox = std::make_shared<widget::ButtonBox>(Point{0, 2}, Dimensions{20, 1}, buttonBoxButtons);
    buttonBox->setLabel("buttonBox");
    auto buttonBox2 = std::make_shared<widget::ButtonBox>(Point{1, 4}, Dimensions{20, 1}, buttonBoxButtons2);
    buttonBox2->setLabel("buttonBox2");

    window->addWidget(label);
    window->addWidget(buttonBox);
    window->setTitle("Test Window");
    window2->setTitle("Second Window");
    buttonBox2->setTitle("Button Box 2");

    Widget::Signal buttonAction = [&screen](Widget& widget, std::string_view action) {
        auto toast = std::make_shared<guart::widget::Toast>(guart::Point{20, 20}, "Button clicked: " + std::string(action));
        screen.addWidget(toast);
        screen.invalidate();
    };

    buttonBox2->onAction = buttonAction;
    buttonBox->onAction = buttonAction;
    screen.addWidget(buttonBox2);

    // auto modalWindow = std::make_shared<widget::ModalWindow>(
    //     Point{5, 5}, Dimensions{30, 10}, "This is a modal window\nAlso checking if it works\nwith multiple lines.", 
    //     widget::ButtonBox::Buttons{"OK", "Cancel"});
    // modalWindow->setTitle("Modal Window");
    // modalWindow->setLabel("modalWindow");
    // screen.addWidget(modalWindow);

    // Widget::Signal modalAction = [&screen](Widget& widget, std::string_view action) {
        
    //     auto toast = std::make_shared<guart::widget::Toast>(guart::Point{20, 20}, "Button clicked: " + std::string(action));
    //     screen.addWidget(toast);
    //     screen.invalidate();
    //     toast->onDispose = [&widget](Widget& w, std::string_view) {
    //         widget.dispose();
    //     };
    // };
    // modalWindow->onAction = modalAction;


    auto list = std::make_shared<widget::List>(Point{30, 6}, Dimensions{20, 5}, 
        widget::List::Items{"Item 1", "Item 2", "Item 3", "Item 4", "Item 5", "Item 6", "Item 7", "Item 8", "Item 9", "Item 10"},
        true);

    Widget::Signal listAction = [&screen](Widget& widget, std::string_view action) {
        auto toast = std::make_shared<guart::widget::Toast>(guart::Point{20, 20}, "List item selected: " + std::string(action));
        screen.addWidget(toast);
        screen.invalidate();
    };
    list->onAction = listAction;

    screen.addWidget(list);
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
