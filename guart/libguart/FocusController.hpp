#pragma once

/**
 * @file FocusController.hpp
 * @author Adrian Szczepanski
 * @date 09-07-2025
 */

#ifndef GUART_FOCUS_CONTROLLER_LIMIT
#define GUART_FOCUS_CONTROLLER_LIMIT 50
#endif

#include <etl/list.h>

#include <etl/string.h>

namespace guart
{
    class Focusable;

    class FocusController
    {
    public:
        static constexpr size_t FOCUSABLE_LIMIT = GUART_FOCUS_CONTROLLER_LIMIT;

        virtual ~FocusController() = default;

        void addFocusable(Focusable*, bool setFocus = true);
        void removeFocusable(Focusable* widget);
        bool isFocused(const Focusable*) const;
        
        virtual bool processInput(const etl::string_view&);

    protected:
        virtual void resetOutput() = 0;

    private:
        etl::list<Focusable*, FOCUSABLE_LIMIT>::iterator focusedWidget = focusableWidgets.end();
        etl::list<Focusable*, FOCUSABLE_LIMIT> focusableWidgets;
    };
}