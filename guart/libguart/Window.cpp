#include "Window.hpp"

#include <iostream>

#include "Charset.hpp"

using namespace guart;

Window::Window(const Point& p, const Dimensions& d, bool isBold)
    : position(p)
    , dimensions(d)
    , isBold(isBold)
{
}

void Window::draw() const
{
    for (int i = 0; i < position.y; ++i)
        std::cout << std::endl;
    
    for (int i = 0; i < position.x; ++i)
        std::cout << ' ';
    std::cout << border::bold::TOP_LEFT;
    for (int i = 0; i < dimensions.width; ++i)
        std::cout << border::bold::HORIZONTAL;
    std::cout << border::bold::TOP_RIGHT << std::endl;

    for (int i = 0; i < dimensions.height; ++i)
    {
        for (int j = 0; j < position.x; ++j)
            std::cout << ' ';
        std::cout << border::bold::VERTICAL;
        for (int j = 0; j < dimensions.width; ++j)
            std::cout << ' ';
        std::cout << border::bold::VERTICAL << std::endl;
    }

    for (int i = 0; i < position.x; ++i)
        std::cout << ' ';
    std::cout << border::bold::LOWER_LEFT;
    for (int i = 0; i < dimensions.width; ++i)
        std::cout << border::bold::HORIZONTAL;
    std::cout << border::bold::LOWER_RIGHT << std::endl;
}