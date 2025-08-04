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
        bool isFocused(const Focusable*) const;
        
        virtual bool processInput(const std::string_view&);

    protected:
        void gotoNextFocusable();
        void gotoPreviousFocusable();

        virtual void resetOutput() = 0;
        virtual void refreshOutput() = 0;

    private:
        std::list<Focusable*>::iterator focused = focusables.end();
        std::list<Focusable*> focusables;
    };
}