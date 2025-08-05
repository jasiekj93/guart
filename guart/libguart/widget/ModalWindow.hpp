#pragma once

/**
 * @file Window.hpp
 * @author Adrian Szczepanski
 * @date 01-07-2025
 */

#include <libguart/widget/Window.hpp>

namespace guart::widget
{
    class ModalWindow : public Window
    {
    public:
        ModalWindow(const Point&, const Dimensions&);

        inline bool isModal() const { return true; }
    };
}