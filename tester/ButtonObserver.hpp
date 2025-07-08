#pragma once

#include <libguart/Widget.hpp>
#include <libguart/Screen.hpp>

class ButtonObserver : public guart::Widget::Observer
{
public:
    ButtonObserver(guart::Screen* screen) : screen(screen) {}

    void actionCallback(const guart::Widget& widget, std::string_view action = "") override;

private:
    guart::Screen* screen;
};