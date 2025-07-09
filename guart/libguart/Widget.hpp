#pragma once

/**
 * @file Widget.hpp
 * @author Adrian Szczepanski
 * @date 01-07-2025
 */

#include <memory>
#include <vector>
#include <string>
#include <functional>

#include <libguart/Point.hpp>
#include <libguart/Drawer.hpp>
#include <libguart/Parent.hpp>

namespace guart
{
    class FocusController;

    class Widget : public Parent
    {
    public:
        using Signal = std::function<void(Widget&, std::string_view)>;

        Widget(const Point& position, std::string_view label = "");

        Point getPosition() const;
        virtual Point getContentPosition() const override { return getPosition(); }

        inline auto& getLabel() const { return label; }
        inline void setLabel(std::string_view l) { label = l; }

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
        std::string label;
        
        Parent* parent = nullptr;
    };
}