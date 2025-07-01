#include "Screen.hpp"

using namespace guart;

Screen::Screen(Output& output)
    : output(output)
{
}

void Screen::invalidate() const
{
    clean();
    invalidateWidgets();
}

void Screen::moveCursor(const Point& p) const
{
    std::string cursorPosition = "\e[" + std::to_string(p.y) + ";" + std::to_string(p.x) + "H";
    output << "\e[H" << cursorPosition; 
    output.flush();
}

void Screen::clean() const
{
    output << "\e[2J"; 
    output << "\e[H"; 
}