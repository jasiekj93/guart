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
#include <libguart/Parent.hpp>

namespace guart
{
    class FocusController;

    class Widget : public Parent
    {
    public:
        class Observer
        {
        public:
            virtual ~Observer() = default;

            virtual void actionCallback(const Widget& widget, std::string_view action = "") = 0;
        };

        Widget(const Point& position, std::string_view label = "");
        virtual ~Widget() = default;

        void invalidate() const;

        void addWidget(const std::shared_ptr<Widget>&);
        void removeWidget(Widget* child) override;

        void setDrawer(Drawer* d); 
        void setFocusController(FocusController*); 

        Point getPosition() const;
        virtual Point getContentPosition() const override { return getPosition(); }

        inline auto& getLabel() const { return label; }
        inline void setLabel(std::string_view l) { label = l; }
        inline void setObserver(Observer* obs) { observer = obs; }

        inline void moveTo(const Point& p) { position = p; }
        inline void setParent(Parent* p) { parent = p; }
        inline auto& getChildren() { return children; }

        void setFocus(bool); 
        inline bool isFocused() const { return focusFlag; }

        virtual std::string_view getType() const = 0;
        virtual bool isFocusable() const { return false; }
        virtual bool isModal() const { return false; }

        virtual void processInput(const std::string_view&) {}

    protected:
        void remove(Widget*);

        Observer* observer = nullptr;

    private:
        Point position;
        std::string label;
        std::vector<std::shared_ptr<Widget>> children;
        bool focusFlag = false;

        Drawer* drawer = nullptr;
        Parent* parent = nullptr;
        FocusController* focusController = nullptr;
    };
}