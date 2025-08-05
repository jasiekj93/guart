#pragma once

/**
 * @file FocusController.hpp
 * @author Adrian Szczepanski
 * @date 09-07-2025
 */

#include <list>
#include <string>

namespace guart
{
    class Focusable;

    class FocusController
    {
    public:
        virtual ~FocusController() = default;

        void addFocusable(Focusable*, bool setFocus = true);
        void removeFocusable(Focusable* widget);
        bool isWidgetFocused(const Focusable*) const;
        

    protected:
        void gotoNextFocusable();
        void gotoPreviousFocusable();

        std::list<Focusable*>::iterator focused = focusables.end();
        std::list<Focusable*> focusables;
    };
}