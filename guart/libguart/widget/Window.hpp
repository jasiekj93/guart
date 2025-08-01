#pragma once

/**
 * @file Window.hpp
 * @author Adrian Szczepanski
 * @date 01-07-2025
 */

#include <libguart/Widget.hpp>
#include <libguart/Dimensions.hpp>

namespace guart::widget
{
    class Window : public Widget
    {
    public:
        Window(const Point&, const Dimensions&);

        void resize(const Dimensions& d); 

        inline std::string_view getType() const override { return "Window"; }
        inline Point getContentPosition() const override { return getPosition() + Point{1, 0}; }

        inline void setTitle(std::string_view l) { title = l; }
        inline std::string_view getTitle() const { return title; }
        inline auto& getDimensions() const { return dimensions; }

    private:
        Dimensions dimensions;
        std::string title;
    };
}