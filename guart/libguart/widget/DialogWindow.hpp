#pragma once

/**
 * @file DialogWindow.hpp
 * @author Adrian Szczepanski
 * @date 05-08-2025
 */

#include <libguart/widget/Window.hpp>
#include <libguart/widget/TextBox.hpp>
#include <libguart/widget/ButtonBox.hpp>
#include <libguart/widget/Line.hpp>

namespace guart::widget
{
    class DialogWindow : public Window
    {
    public:
        DialogWindow(const Point&, const Dimensions&, 
            std::string_view message,
            const ButtonBox::Buttons& buttons);

        inline std::string_view getType() const override { return "Window"; }
        inline bool isModal() const override { return true; }
        inline bool isFocusable() const override { return true; }

        void processKey(const std::string_view&) override;
    };
}