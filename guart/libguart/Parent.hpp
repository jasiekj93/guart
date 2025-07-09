#pragma once

/**
 * @file Parent.hpp
 * @author Adrian Szczepanski
 * @date 08-07-2025
 */

#include <memory>
#include <vector>
#include <string_view>

#include <libguart/Point.hpp>
#include <libguart/Drawable.hpp>
#include <libguart/Focusable.hpp>

namespace guart
{
    class Widget;

    class Parent : public Drawable, public Focusable
    {
    public:
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

        virtual std::string_view getType() const override = 0;

        // Focusable
        void setFocusController(FocusController* controller) override;
        inline virtual void focusChangeCallback(bool) override { invalidate(); }

    private:
        std::vector<std::shared_ptr<Widget>> children;
    };
}