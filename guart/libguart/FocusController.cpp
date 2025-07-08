#include "FocusController.hpp"

#include <algorithm>

#include <libguart/Key.hpp>

using namespace guart;

void FocusController::addFocusableWidget(Widget* widget)
{
    if(not widget)
        return;

    if(auto it = std::find(focusableWidgets.begin(), focusableWidgets.end(), widget);
       it == focusableWidgets.end())
    {
        if(widget->isModal())
        {
            for(auto& w : focusableWidgets)
                w->setFocus(false); 

            widget->setFocus(true);
            modalWidget = widget;
        }
        else
        {
            focusableWidgets.push_back(widget);

            if(focusedIndex < 0)
            {
                focusedIndex = 0; 
                widget->setFocus(true);
            }
        }
    }
}

void FocusController::removeFocusableWidget(Widget* widget)
{
    if(widget == modalWidget)
    {
        modalWidget->setFocus(false);
        modalWidget = nullptr;

        if(focusedIndex >= 0)
            focusableWidgets[focusedIndex]->setFocus(true);
    }
    else
    {
        focusableWidgets.erase(std::remove_if(focusableWidgets.begin(), focusableWidgets.end(),
                                            [widget](const Widget* w) { return w == widget; }),
                            focusableWidgets.end());
    }

}

bool FocusController::processInput(const std::string_view& input)
{
    if (input.empty() or focusableWidgets.empty())
        return true;

    if(input == key::CTRL_C or input == key::CTRL_D)
    {
        resetOutput();
        return false; // Exit the application
    }
    else if (input == key::TAB)
    {
        if(modalWidget)
            return true; // Do not change focus if the current widget is modal

        auto oldIndex = focusedIndex;
        focusedIndex = (focusedIndex + 1) % focusableWidgets.size();

        focusableWidgets[oldIndex]->setFocus(false);
        focusableWidgets[focusedIndex]->setFocus(true);

        focusableWidgets[focusedIndex]->invalidate();
        focusableWidgets[oldIndex]->invalidate();
    }
    // else if (input == key::SHIFT_TAB)
    //     focusedIndex = (focusedIndex - 1 + focusableWidgets.size()) % focusableWidgets.size();
    else
    {
        if(modalWidget)
            modalWidget->processInput(input);
        else
            focusableWidgets[focusedIndex]->processInput(input);
    }

    return true;
}