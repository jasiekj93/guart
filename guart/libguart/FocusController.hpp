#pragma once

#include <list>

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
        //TODO vector i index zamiast iteratora (przy przenoszeniu wektora jebie się iterator)
        //albo lista
        std::list<Widget*>::iterator focusedWidget = focusableWidgets.end();
        std::list<Widget*> focusableWidgets;
    };
}