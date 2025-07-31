#pragma once

/**
 * @file Parent.hpp
 * @author Adrian Szczepanski
 * @date 08-07-2025
 */

#ifndef GUART_PARENT_CHILDREN_LIMIT
#define GUART_PARENT_CHILDREN_LIMIT 10
#endif

#include <memory>

#include <etl/vector.h>
#include <etl/string.h>

#include <libguart/Point.hpp>
#include <libguart/Drawable.hpp>
#include <libguart/Focusable.hpp>

namespace guart
{
    class Widget;

    class Parent : public Drawable, public Focusable
    {
    public:
        static constexpr size_t CHILDREN_LIMIT = GUART_PARENT_CHILDREN_LIMIT;

        virtual ~Parent() = default;

        void addWidget(const std::shared_ptr<Widget>&);
        void removeWidget(Widget* child);

        inline auto& getChildren() { return children; }
        inline const auto& getChildren() const { return children; }

        virtual void dispose();
        void childFocusedCallback(Widget* child);

        virtual inline Point getContentPosition() const { return Point{0, 0}; }

        // Drawable
        virtual void invalidate() const override;
        void setDrawer(Drawer* d) override;
        virtual void setActive(bool active) override; 

        virtual etl::string_view getType() const override = 0;

        // Focusable
        void setFocusController(FocusController* controller) override;
        inline virtual void focusChangeCallback(bool) override { invalidate(); }

    private:
        etl::vector<std::shared_ptr<Widget>, CHILDREN_LIMIT> children;
    };
}