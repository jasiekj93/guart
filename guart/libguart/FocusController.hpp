#pragma once

#include <deque>

#include <libguart/Widget.hpp>

namespace guart
{
    class FocusController
    {
    public:
        virtual ~FocusController() = default;

        void addFocusableWidget(Widget*);
        void removeFocusableWidget(Widget* widget);
        
        bool processInput(const std::string_view&);
        bool isWidgetFocused(const Widget*) const;

    protected:
        virtual void resetOutput() = 0;

    private:
        std::deque<Widget*> focusableWidgets;
        std::deque<Widget*>::iterator focusedWidget = focusableWidgets.end();
    };
}