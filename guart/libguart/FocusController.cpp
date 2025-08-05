#include "FocusController.hpp"
#include "Focusable.hpp"

#include <algorithm>

#include <libguart/Key.hpp>

using namespace guart;

void FocusController::addFocusable(Focusable* widget, bool setFocus)
{
    if(not widget)
        return;

    if(auto it = std::find(focusables.begin(), focusables.end(), widget);
       it == focusables.end())
    {
        if(widget->isModal())
        {
            if(focused == focusables.begin())
            {
                focusables.push_front(widget);
                focused = focusables.begin();
            }
            else
            {
                focusables.insert(focused, widget);
                focused--;
            }
        }
        else 
        {
            if(setFocus)
            {
                focusables.push_front(widget);
                focused = focusables.begin();
            }
            else
                focusables.insert(focused, widget);
        }
    }
}

void FocusController::removeFocusable(Focusable* widget)
{
    if(widget == nullptr)
        return;

    auto it = std::find(focusables.begin(), focusables.end(), widget);

    if(it == focusables.end())
        return; 

    if(focused == it)
    {
        if(focusables.size() == 1)
            focused = focusables.end();
        else if (focused == std::prev(focusables.end()))
            focused--;
        else
            focused++;
    } 

    focusables.erase(it);
}

void FocusController::gotoNextFocusable()
{
    if((*focused)->isModal())
        return; 

    auto oldIt = focused;
    focused++;

    if(focused == focusables.end())
        focused = focusables.begin();

    (*oldIt)->focusChangeCallback(false);
    (*focused)->focusChangeCallback(true);
}

void FocusController::gotoPreviousFocusable()
{
    if((*focused)->isModal())
        return; 

    auto oldIt = focused;
    if(focused == focusables.begin())
        focused = std::prev(focusables.end());
    else
        focused--;

    (*oldIt)->focusChangeCallback(false);
    (*focused)->focusChangeCallback(true);
}

bool FocusController::isWidgetFocused(const Focusable* w) const
{
    return (w == *focused);
}
