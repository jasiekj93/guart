#include "Screen.hpp"

#include <algorithm>

#include <libguart/drawer/Label.hpp>
#include <libguart/drawer/Window.hpp>
#include <libguart/drawer/ButtonBox.hpp>
#include <libguart/drawer/Toast.hpp>
#include <libguart/drawer/TextBox.hpp>
#include <libguart/drawer/Line.hpp>
#include <libguart/drawer/List.hpp>
#include <libguart/Key.hpp>

using namespace guart;

Screen::Screen(Output& output)
    : output(output)
{
    focusController = this;
    drawer = this;

    drawers["Label"] = std::make_unique<drawer::Label>(*this);
    drawers["Window"] = std::make_unique<drawer::Window>(*this);
    drawers["ButtonBox"] = std::make_unique<drawer::ButtonBox>(*this);
    drawers["Toast"] = std::make_unique<drawer::Toast>(*this);
    drawers["TextBox"] = std::make_unique<drawer::TextBox>(*this);
    drawers["Line"] = std::make_unique<drawer::Line>(*this);
    drawers["List"] = std::make_unique<drawer::List>(*this);
}

void Screen::invalidate() const
{
    clear();
    for(auto& widget : getChildren())
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

void Screen::draw(const Drawable& drawable) const
{
    const auto& drawer = drawers.find(drawable.getType());

    if (drawer != drawers.end())
        drawer->second->draw(drawable);
}

void Screen::resetOutput()
{
    output << "\e[?25h"; // Show cursor
    output << "\e[0m"; // Reset terminal colors
    output << "\e[2J";  // Clear screen
    output << "\e[H";  // Move cursor to home position
    output.flush();
}