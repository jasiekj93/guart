#include "DialogWindow.hpp"

using namespace guart;
using namespace guart::widget;

DialogWindow::DialogWindow(const Point& p, const Dimensions& d, 
    std::string_view message, 
    const ButtonBox::Buttons& buttons)
    : Window(p, d)
{
    auto textBox = std::make_shared<TextBox>(Point{0, 0}, message);
    textBox->setLabel("textBox-modal");
    auto buttonBox = std::make_shared<ButtonBox>(Point{0, d.height - 1}, 
        Dimensions{d.width - 2, 1}, 
        buttons,
        false);
    buttonBox->setLabel("buttonBox-modal");
    auto line = std::make_shared<Line>(Point{0, d.height - 2}, d.width, false);
    line->setLabel("line-modal");

    addWidget(textBox);
    addWidget(buttonBox);
    addWidget(line);

    buttonBox->onAction = [this](Widget& w, std::string_view action) {
        if(onAction)
            onAction(*this, action);
    };
}

void DialogWindow::processKey(const std::string_view& input)
{
    getChildren()[1]->processKey(input);
}
