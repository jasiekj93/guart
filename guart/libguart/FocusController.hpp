#pragma once

#include <vector>

#include <libguart/Widget.hpp>

namespace guart
{
    class FocusController
    {
    public:
        virtual ~FocusController() = default;

        void addFocusableWidget(Widget*);
        bool processInput(const std::string_view&);

    protected:
        virtual void resetOutput() = 0;

    private:
        std::vector<Widget*> focusableWidgets;
        int focusedIndex = -1;
    };
}