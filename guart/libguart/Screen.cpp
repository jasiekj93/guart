#include "Screen.hpp"
#include <libguart/drawer/Label.hpp>
#include <libguart/drawer/Window.hpp>
#include <libguart/drawer/ButtonBox.hpp>
#include <libguart/drawer/Toast.hpp>
#include <libguart/Key.hpp>

using namespace guart;

Screen::Screen(Output& output)
    : output(output)
{
    drawers["Label"] = std::make_unique<drawer::Label>(*this);
    drawers["Window"] = std::make_unique<drawer::Window>(*this);
    drawers["ButtonBox"] = std::make_unique<drawer::ButtonBox>(*this);
    drawers["Toast"] = std::make_unique<drawer::Toast>(*this);
}

void Screen::addWidget(const std::shared_ptr<Widget>& widget)
{
    if(not widget)
        return;

    widget->setDrawer(this);
    widget->setFocusController(this);
    widgets.push_back(widget);
}

void Screen::invalidate() const
{
    clear();
    for(auto& widget : widgets)
    {
        if(widget)
            widget->invalidate();
    }
}

void Screen::moveCursor(const Point& p) const
{
    std::string cursorPosition = "\e[" + std::to_string(p.y) + ";" + std::to_string(p.x) + "H";
    output << "\e[H"; 
    output.flush();
    output << cursorPosition;
    output.flush();
}

void Screen::clear() const
{
    output << "\e[?25l"; // Hide cursor
    output << "\e[2J";  // Clear screen
    output << "\e[H";  // Move cursor to home position
}

void Screen::draw(const Widget& widget) const
{
    const auto& drawer = drawers.find(widget.getType());

    if (drawer != drawers.end())
        drawer->second->draw(widget);
}

void Screen::resetOutput()
{
    output << "\e[?25h"; // Show cursor
    output << "\e[0m"; // Reset terminal colors
    output << "\e[2J";  // Clear screen
    output << "\e[H";  // Move cursor to home position
    output.flush();
}