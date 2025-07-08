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

    addWidget(textBox);
    addWidget(buttonBox);
    buttonBox->setObserver(this);
}

void ModalWindow::actionCallback(const Widget& widget, std::string_view action)
{
    if(observer)
        observer->actionCallback(widget, action);
}

void ModalWindow::processInput(const std::string_view& input)
{
    getChildren()[1]->processInput(input);
}
