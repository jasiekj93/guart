#pragma once

/**
 * @file ModalWindow.hpp
 * @author Adrian Szczepanski
 * @date 01-07-2025
 */

#include <libguart/widget/Window.hpp>
#include <libguart/widget/TextBox.hpp>
#include <libguart/widget/ButtonBox.hpp>
#include <libguart/widget/Line.hpp>

namespace guart::widget
{
    class ModalWindow : public Window
    {
    public:
        ModalWindow(const Point&, const Dimensions&, 
            std::string_view message,
            const ButtonBox::Buttons& buttons);

        inline std::string_view getType() const override { return "Window"; }
        inline bool isModal() const override { return true; }
        inline bool isFocusable() const override { return true; }

        void processInput(const std::string_view&) override;
    };
}