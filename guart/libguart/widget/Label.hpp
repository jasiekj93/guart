#pragma once

#include <string>

#include <libguart/Widget.hpp>

namespace guart::widget
{
    class Label : public Widget
    {
    public:
        Label(const Point& position, const std::string_view& text = "");

        inline void setText(const std::string_view& t) { text = t; }
        inline auto& getText() const { return text; }

        inline std::string_view getType() const override { return "Label"; }

    private:
        std::string text;
    };
} 