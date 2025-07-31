#pragma once

/**
 * @file Label.hpp
 * @author Adrian Szczepanski
 * @date 08-07-2025
 */

#ifndef GUART_WIDGET_LABEL_LIMIT
#define GUART_WIDGET_LABEL_LIMIT 32
#endif

#include <etl/string.h>

#include <libguart/Widget.hpp>

namespace guart::widget
{
    class Label : public Widget
    {
    public:
        static constexpr size_t LIMIT = GUART_WIDGET_LABEL_LIMIT;

        using Text = etl::string<LIMIT>;

        Label(const Point& position, const etl::string_view& text = "");

        inline void setText(const etl::string_view& t) { text = t; }
        inline auto& getText() const { return text; }

        inline etl::string_view getType() const override { return "Label"; }

    private:
        Text text;
    };
} 