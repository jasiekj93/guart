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
        focusableWidgets.push_back(widget);

        if(focusedIndex < 0)
        {
            focusedIndex = 0; 
            widget->setFocus(true);
        }

        if(widget->isModal())
        {
            for(auto& w : focusableWidgets)
                w->setFocus(false); 

            widget->setFocus(true);
            focusedIndex = focusableWidgets.size() - 1; // Set focus to the last modal widget
        }
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
        if(focusableWidgets[focusedIndex]->isModal())
            return true; // Do not change focus if the current widget is modal

        auto oldIndex = focusedIndex;
        focusedIndex = (focusedIndex + 1) % focusableWidgets.size();

        focusableWidgets[oldIndex]->setFocus(false);
        focusableWidgets[focusedIndex]->setFocus(true);
    }
    // else if (input == key::SHIFT_TAB)
    //     focusedIndex = (focusedIndex - 1 + focusableWidgets.size()) % focusableWidgets.size();
    else
        focusableWidgets[focusedIndex]->processInput(input);

    return true;
}