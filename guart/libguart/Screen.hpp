#pragma once

/**
 * @file Screen.hpp
 * @author Adrian Szczepanski
 * @date 01-07-2025
 */

#include <memory>
#include <vector>
#include <map>

#include <libguart/Output.hpp>
#include <libguart/Canvas.hpp>
#include <libguart/Widget.hpp>
#include <libguart/Parent.hpp>
#include <libguart/FocusController.hpp>

namespace guart
{
    class Screen : public Canvas, public Drawer, public FocusController, public Parent
    {
    public:
        explicit Screen(Output&); 

        //Parent
        void invalidate() const override;
        inline std::string_view getType() const override { return "Screen"; }

        //Canvas
        void moveCursor(const Point&) const override;
        inline Output& getOutput() const override { return output; }
        void clear() const override;

        //Drawer
        void draw(const Drawable&) const override;

    protected:
        //FocusController
        void resetOutput() override;

        //Parent
        inline void processKey(const std::string_view& input) override {}
        inline virtual void focusChangeCallback(bool) override { }

    private:
        Output& output;
        std::map<std::string_view, std::unique_ptr<Drawer>> drawers;
    };
}