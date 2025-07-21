#pragma once

/**
 * @file TextField.hpp
 * @author Adrian Szczepanski
 * @date 21-07-2025
 */

#include <string>

#include <libguart/Widget.hpp>

namespace guart::widget
{
    class TextField : public Widget
    {
    public:
        TextField(const Point& position, size_t length, const std::string_view& text = "");

        inline void setText(const std::string_view& t) { text = t; }
        inline auto& getText() const { return text; }

        inline auto getLength() const { return length; }
        inline void setLength(size_t l) { length = l; }

        inline std::string_view getType() const override { return "TextField"; }
        inline bool isFocusable() const { return true; }

        virtual void processKey(const std::string_view&) override;

    private:
        std::string text;
        size_t length = 0; 
    };
} 