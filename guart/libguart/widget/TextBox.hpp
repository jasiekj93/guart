#pragma once

/**
 * @file TextBox.hpp
 * @author Adrian Szczepanski
 * @date 08-07-2025
 */

#include <libguart/widget/Label.hpp>

namespace guart::widget
{
    class TextBox : public Label
    {
    public:
        TextBox(const Point& position, const std::string_view& text = "")
            : Label(position, text)
        {
        }

        inline std::string_view getType() const override { return "TextBox"; }
    };
} 