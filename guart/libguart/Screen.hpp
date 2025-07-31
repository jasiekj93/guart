#pragma once

/**
 * @file Screen.hpp
 * @author Adrian Szczepanski
 * @date 01-07-2025
 */

#ifndef GUART_SCREEN_DRAWERS_LIMIT
#define GUART_SCREEN_DRAWERS_LIMIT 32
#endif

#include <memory>

#include <etl/map.h>

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
        static constexpr size_t DRAWERS_LIMIT = GUART_SCREEN_DRAWERS_LIMIT;

        explicit Screen(Output&); 

        //Parent
        void invalidate() const override;
        inline etl::string_view getType() const override { return "Screen"; }

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
        inline void processKey(const etl::string_view& input) override {}
        inline virtual void focusChangeCallback(bool) override { }

    private:
        Output& output;
        etl::map<etl::string_view, std::unique_ptr<Drawer>, DRAWERS_LIMIT> drawers;
    };
}