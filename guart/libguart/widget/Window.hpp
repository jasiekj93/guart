#pragma once

/**
 * @file Window.hpp
 * @author Adrian Szczepanski
 * @date 01-07-2025
 */

#ifndef GUART_WIDGET_WINDOW_TITLE_LIMIT
#define GUART_WIDGET_WINDOW_TITLE_LIMIT 16
#endif

#include <libguart/Widget.hpp>
#include <libguart/Dimensions.hpp>

namespace guart::widget
{
    class Window : public Widget
    {
    public:
        static constexpr size_t TITLE_LIMIT = GUART_WIDGET_WINDOW_TITLE_LIMIT;

        Window(const Point&, const Dimensions&);

        void resize(const Dimensions& d); 

        inline etl::string_view getType() const override { return "Window"; }
        inline Point getContentPosition() const override { return getPosition() + Point{1, 1}; }

        inline void setTitle(etl::string_view l) { title = l; }
        inline etl::string_view getTitle() const { return title; }
        inline auto& getDimensions() const { return dimensions; }

    private:
        Dimensions dimensions;
        etl::string<TITLE_LIMIT> title;
    };
}