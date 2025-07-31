#pragma once

/**
 * @file Widget.hpp
 * @author Adrian Szczepanski
 * @date 01-07-2025
 */

#ifndef GUART_WIDGET_LABEL_LIMIT
#define GUART_WIDGET_LABEL_LIMIT 16
#endif

#include <memory>
#include <functional>

#include <etl/string.h>

#include <libguart/Point.hpp>
#include <libguart/Drawer.hpp>
#include <libguart/Parent.hpp>

namespace guart
{
    class FocusController;

    class Widget : public Parent
    {
    public:
        static constexpr size_t LABEL_LIMIT = GUART_WIDGET_LABEL_LIMIT;

        using Signal = std::function<void(Widget&, etl::string_view)>;
        using Label = etl::string<LABEL_LIMIT>;

        Widget(const Point& position, etl::string_view label = "");

        Point getPosition() const;
        virtual Point getContentPosition() const override { return getPosition(); }

        inline auto& getLabel() const { return label; }
        inline void setLabel(etl::string_view l) { label = l; }

        inline void moveTo(const Point& p) { position = p; }
        inline void setParent(Parent* p) { parent = p; }

        // Parent
        void dispose() override;
        bool isFocused() const override; 
        void focusChangeCallback(bool isFocused) override;

        Signal onAction;
        Signal onFocus;
        Signal onDispose;

    private:
        Point position;
        Label label;

        Parent* parent = nullptr;
    };
}