#include "ModalWindow.hpp"

using namespace guart;
using namespace guart::widget;

ModalWindow::ModalWindow(const Point& p, const Dimensions& d, 
    std::string_view message, 
    const ButtonBox::Buttons& buttons)
    : Window(p, d)
{
    auto textBox = std::make_shared<TextBox>(Point{1, 1}, message);
    auto buttonBox = std::make_shared<ButtonBox>(Point{0, d.height - 3}, 
        Dimensions{d.width - 2, 1}, 
        buttons,
        false);
    auto line = std::make_shared<Line>(Point{0, d.height - 4}, d.width, false);

    addWidget(textBox);
    addWidget(buttonBox);
    addWidget(line);
    buttonBox->setObserver(this);
}

void ModalWindow::actionCallback(Widget& widget, std::string_view action)
{
    if(onAction)
        onAction(widget, action);
}

void ModalWindow::processInput(const std::string_view& input)
{
    getChildren()[1]->processInput(input);
}
