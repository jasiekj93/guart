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
    static std::shared_ptr<widget::ModalWindow> modalWindow;

    modalWindow = std::make_shared<widget::ModalWindow>(
        Point{30, 20}, Dimensions{31, 20});
    modalWindow->setTitle("Form");
    modalWindow->setLabel("modalWindow");



    auto nameLabel = std::make_shared<widget::Label>(Point{1, 0}, "Name:");
    auto surnameLabel = std::make_shared<widget::Label>(Point{1, 2}, "Surname:");
    auto emailLabel = std::make_shared<widget::Label>(Point{1, 4}, "E-mail:");
    auto streetLabel = std::make_shared<widget::Label>(Point{1, 6}, "Street:");
    auto cityLabel = std::make_shared<widget::Label>(Point{1, 8}, "City:");

    auto nameField = std::make_shared<widget::TextField>(Point{9, 0}, 20);
    auto surnameField = std::make_shared<widget::TextField>(Point{9, 2}, 20);
    auto emailField = std::make_shared<widget::TextField>(Point{9, 4}, 20);
    auto streetField = std::make_shared<widget::TextField>(Point{9, 6}, 20);
    auto cityField = std::make_shared<widget::TextField>(Point{9, 8}, 20);

    auto buttonBox = std::make_shared<widget::ButtonBox>(Point{0, 10}, Dimensions{28, 1}, 
        widget::ButtonBox::Buttons{"Submit", "Cancel"}, false);

    buttonBox->onAction = [&](Widget& widget, std::string_view action) {
        std::string message = "Form submitted with action: " + std::string(action);

        auto toast = std::make_shared<guart::widget::Toast>(guart::Point{20, 20}, message);
        screen.addWidget(toast);
        screen.invalidate();
        toast->onDispose = [](Widget& w, std::string_view) {
            modalWindow->dispose();
        };
    };

    modalWindow->addWidget(nameLabel);
    modalWindow->addWidget(surnameLabel);
    modalWindow->addWidget(emailLabel);
    modalWindow->addWidget(streetLabel);
    modalWindow->addWidget(cityLabel);

    modalWindow->addWidget(buttonBox);
    modalWindow->addWidget(cityField);
    modalWindow->addWidget(streetField);
    modalWindow->addWidget(emailField);
    modalWindow->addWidget(surnameField);
    modalWindow->addWidget(nameField);
    screen.addWidget(modalWindow);
}

int main(int argc, char* argv[])
{
    CliOutput output;
    // Serial output("/dev/ttyUSB1");

    Screen screen(output);

    auto window = std::make_shared<widget::Window>(Point{10, 10}, Dimensions{30, 10});
    window->setLabel("window");
    window->setTitle("Buttons");

    widget::ButtonBox::Buttons buttonBoxButtons{ "Modal" };
    widget::ButtonBox::Buttons buttonBoxButtons2{ "Nothing" };
    
    auto buttonBox = std::make_shared<widget::ButtonBox>(Point{0, 2}, Dimensions{20, 1}, buttonBoxButtons);
    buttonBox->setLabel("buttonBox");

    auto buttonBox2 = std::make_shared<widget::ButtonBox>(Point{0, 5}, Dimensions{20, 1}, buttonBoxButtons2);
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
