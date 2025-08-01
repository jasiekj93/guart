#include "FocusController.hpp"
#include "Focusable.hpp"

#include <algorithm>

#include <libguart/Key.hpp>

using namespace guart;

void FocusController::addFocusable(Focusable* widget, bool setFocus)
{
    if(not widget)
        return;

    if(auto it = std::find(focusableWidgets.begin(), focusableWidgets.end(), widget);
       it == focusableWidgets.end())
    {
        if(widget->isModal())
        {
            if(focusedWidget == focusableWidgets.begin())
            {
                focusableWidgets.push_front(widget);
                focusedWidget = focusableWidgets.begin();
            }
            else
            {
                focusableWidgets.insert(focusedWidget, widget);
                focusedWidget--;
            }
        }
        else 
        {
            if(setFocus)
            {
                focusableWidgets.push_front(widget);
                focusedWidget = focusableWidgets.begin();
            }
            else
                focusableWidgets.insert(focusedWidget, widget);
        }
    }
}

void FocusController::removeFocusable(Focusable* widget)
{
    if(widget == nullptr)
        return;

    auto it = std::find(focusableWidgets.begin(), focusableWidgets.end(), widget);

    if(it == focusableWidgets.end())
        return; 

    if(focusedWidget == it)
    {
        if(focusableWidgets.size() == 1)
            focusedWidget = focusableWidgets.end();
        else if (focusedWidget == std::prev(focusableWidgets.end()))
            focusedWidget--;
        else
            focusedWidget++;
    } 

    focusableWidgets.erase(it);
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
        if((*focusedWidget)->isModal())
            return true; // Do not change focus if the current widget is modal

        auto oldIt = focusedWidget;
        focusedWidget++;

        if(focusedWidget == focusableWidgets.end())
            focusedWidget = focusableWidgets.begin();

        (*oldIt)->focusChangeCallback(false);
        (*focusedWidget)->focusChangeCallback(true);

    }
    else if (input == key::SHIFT_TAB)
    {
        if((*focusedWidget)->isModal())
            return true; // Do not change focus if the current widget is modal

        auto oldIt = focusedWidget;
        if(focusedWidget == focusableWidgets.begin())
            focusedWidget = std::prev(focusableWidgets.end());
        else
            focusedWidget--;

        (*oldIt)->focusChangeCallback(false);
        (*focusedWidget)->focusChangeCallback(true);
    }
    else
        (*focusedWidget)->processKey(input);

    return true;
}

bool FocusController::isFocused(const Focusable* w) const
{
    return (w == *focusedWidget);
}
