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

bool FocusController::processInput(const std::string_view& input)
{
    if (input.empty() or focusables.empty())
        return true;

    if(input == key::CTRL_C or input == key::CTRL_D)
    {
        resetOutput();
        return false; // Exit the application
    }
    else if (input == key::TAB)
        gotoNextFocusable();
    else if (input == key::SHIFT_TAB)
        gotoPreviousFocusable();
    else if (input == key::CTRL_R)
        refreshOutput();    
    else
        (*focused)->processKey(input);

    return true;
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

bool FocusController::isFocused(const Focusable* w) const
{
    return (w == *focused);
}
