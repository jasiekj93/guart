#pragma once

/**
 * @file Window.hpp
 * @author Adrian Szczepanski
 * @date 01-07-2025
 */

#include <vector>
#include <memory>
#include <string>

#include <libguart/Widget.hpp>
#include <libguart/Parent.hpp>

namespace guart
{
    class Window : public Parent, public Widget
    {
    public:
        Window(const Point&, const Dimensions&);

        void invalidate() const override;

        void moveCursor(const Point& p) const override;
        Output& getOutput() const override;

        void resize(const Dimensions& d); 
        inline void setLabel(std::string_view l) { label = l; }

    protected:
        void drawHeader() const;
        void drawBody() const;
        void drawFooter() const;
       
    private:
        Dimensions dimensions;
        std::string label;
    };
}