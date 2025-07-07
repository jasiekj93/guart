#pragma once

/**
 * @file Widget.hpp
 * @author Adrian Szczepanski
 * @date 01-07-2025
 */

#include <memory>
#include <vector>
#include <string>

#include <libguart/Point.hpp>
#include <libguart/Drawer.hpp>

namespace guart
{
    class Widget
    {
    public:
        Widget(const Point& position);
        virtual ~Widget() = default;

        void invalidate() const;
        void addWidget(const std::shared_ptr<Widget>&);
        void setDrawer(Drawer* d); 

        Point getPosition() const;
        virtual Point getContentPosition() const { return getPosition(); }

        inline void moveTo(const Point& p) { position = p; }
        inline void setParent(Widget* p) { parent = p; }
        inline auto& getChildren() { return children; }

        virtual std::string_view getType() const = 0;

        virtual void processInput(const std::string_view&) {}

    private:
        Point position;
        Drawer* drawer = nullptr;

        Widget* parent = nullptr;
        std::vector<std::shared_ptr<Widget>> children;
    };
}