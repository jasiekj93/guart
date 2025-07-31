#pragma once

/**
 * @file TextField.hpp
 * @author Adrian Szczepanski
 * @date 21-07-2025
 */

#ifndef GUART_WIDGET_TEXTFIELD_LENGTH_LIMIT
#define GUART_WIDGET_TEXTFIELD_LENGTH_LIMIT 32
#endif

#include <etl/string.h>

#include <libguart/Widget.hpp>

namespace guart::widget
{
    class TextField : public Widget
    {
    public:
        static constexpr size_t LENGTH_LIMIT = GUART_WIDGET_TEXTFIELD_LENGTH_LIMIT;

        using Text = etl::string<LENGTH_LIMIT>;

        TextField(const Point& position, size_t length, 
            const etl::string_view& text = "", bool addBorder = false);

        inline void setText(const etl::string_view& t) { text = t; }
        inline auto& getText() const { return text; }

        inline auto getLength() const { return length; }
        inline void setLength(size_t l) { length = l; }

        inline bool hasBorder() const { return addBorder; }

        inline etl::string_view getType() const override { return "TextField"; }
        inline bool isFocusable() const { return true; }

        virtual void processKey(const etl::string_view&) override;

    private:
        Text text;
        size_t length = 0; 
        bool addBorder;
    };
} 