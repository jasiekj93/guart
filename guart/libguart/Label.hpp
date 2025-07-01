#pragma once

#include <string>

#include <libguart/Widget.hpp>

namespace guart
{
    class Label : public Widget
    {
    public:
        Label(const Point& position, const std::string_view& text = "");

        void invalidate() const override;

        inline void setText(const std::string_view& t) { text = t; }

    private:
        std::string text;
    };
} 