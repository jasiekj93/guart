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
        virtual ~Widget();

        void invalidate() const;

        void addWidget(const std::shared_ptr<Widget>&);
        void removeWidget(Widget* child) override;

        void setDrawer(Drawer* d); 
        void setFocusController(FocusController*); 

        Point getPosition() const;
        virtual Point getContentPosition() const override { return getPosition(); }

        inline auto& getLabel() const { return label; }
        inline void setLabel(std::string_view l) { label = l; }

        inline void moveTo(const Point& p) { position = p; }
        inline void setParent(Parent* p) { parent = p; }
        inline auto& getChildren() { return children; }
        inline void dispose() { isMarkedDisposed = true; }

        bool isFocused() const;

        virtual std::string_view getType() const = 0;
        virtual bool isFocusable() const { return false; }
        virtual bool isModal() const { return false; }

        virtual void processInput(const std::string_view&) {}

        Signal onAction;
        Signal onFocus;
        Signal onDispose;

    protected:
        inline bool isDisposed() const { return isMarkedDisposed; }
        void remove();

    private:
        Point position;
        std::string label;
        std::vector<std::shared_ptr<Widget>> children;
        bool isMarkedDisposed = false;

        Drawer* drawer = nullptr;
        Parent* parent = nullptr;
        FocusController* focusController = nullptr;
    };
}