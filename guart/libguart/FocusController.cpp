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
            if(focusedWidget == focusableWidgets.begin())
            {
                focusableWidgets.push_front(widget);
                focusedWidget = focusableWidgets.begin();
            }
            else
                focusableWidgets.insert(focusedWidget, widget);
        }
        else 
            focusableWidgets.push_front(widget);

        if(focusableWidgets.size() == 1)
            focusedWidget = focusableWidgets.begin();
    }
}

void FocusController::removeFocusableWidget(Widget* widget)
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
        // else if (focusedWidget == focusableWidgets.begin())
        //     focusedWidget++;
        // else
        //     focusedWidget--;
    } 

    focusableWidgets.erase(it);
    focusableWidgets.resize(focusableWidgets.size());
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

        (*oldIt)->invalidate();
        (*focusedWidget)->invalidate();

    }
    else
        (*focusedWidget)->processInput(input);

    return true;
}

bool FocusController::isWidgetFocused(const Widget* w) const
{
    return (w == *focusedWidget);
}
