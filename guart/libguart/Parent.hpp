#pragma once

/**
 * @file Parent.hpp
 * @author Adrian Szczepanski
 * @date 01-07-2025
 */

#include <vector>
#include <memory>
#include <string>

#include <libguart/Widget.hpp>
#include <libguart/Point.hpp>
#include <libguart/Dimensions.hpp>
#include <libguart/Output.hpp>

namespace guart
{
    class Parent
    {
    public:
        virtual ~Parent() = default;

        void addWidget(const std::shared_ptr<Widget> widget);
        virtual void moveCursor(const Point& p) const = 0;
        virtual Output& getOutput() const = 0;

    protected:
        void invalidateWidgets() const;

    private:
        std::vector<std::shared_ptr<Widget>> widgets;
    };
}