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

    auto slider = std::make_shared<widget::Slider>(Point{50, 18}, Dimensions{20, 12},
        widget::Slider::Items{"0", "20", "40", "60", "80", "100"}, true);
    screen.addWidget(slider);

    // auto modalWindow = std::make_shared<widget::DialogWindow>(
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


    auto list = std::make_shared<widget::CheckList>(Point{30, 6}, Dimensions{20, 10}, 
        widget::List::Items{},
        true);

    list->addItem("window");
    list->addItem("window2");
    list->addItem("buttonBox2");
    list->addItem("slider");

    Widget::Signal listAction = [&](Widget& widget, std::string_view action) {
        if(action == "window")
            window->setActive(not window->isActive());
        else if(action == "buttonBox2")
            buttonBox2->setActive(not buttonBox2->isActive());
        else if(action == "window2")
            window2->setActive(not window2->isActive());
        else if(action == "slider")
            slider->setActive(not slider->isActive());

        screen.invalidate();
    };
    list->onAction = listAction;

    screen.addWidget(list);

    window->setActive(false);
    window2->setActive(false);
    buttonBox2->setActive(false);
    slider->setActive(false);

    auto textField = std::make_shared<widget::TextField>(Point{5, 30}, 20, "Type here...");
    textField->setLabel("textField");
    textField->onAction = [&screen](Widget& widget, std::string_view text) {
        auto toast = std::make_shared<guart::widget::Toast>(guart::Point{20, 20}, "Text entered: " + std::string(text));
        screen.addWidget(toast);
        screen.invalidate();
    };
    screen.addWidget(textField);

    auto calendar = std::make_shared<widget::Calendar>(Point{75, 5}, Date{2025, 6, 30});
    calendar->setLabel("calendar");
    calendar->onAction = [&screen](Widget& widget, std::string_view dateStr) {
        auto toast = std::make_shared<guart::widget::Toast>(guart::Point{20, 20}, "Selected date: " + std::string(dateStr));
        screen.addWidget(toast);
        screen.invalidate();
    };
    screen.addWidget(calendar);

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
