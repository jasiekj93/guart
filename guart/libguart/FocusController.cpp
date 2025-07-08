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
        focusableWidgets.push_front(widget);

        if(widget->isModal() or focusableWidgets.size() == 1)
            focusedWidget = focusableWidgets.begin();
    }
}

void FocusController::removeFocusableWidget(Widget* widget)
{
    if(widget == nullptr)
        return;

    if(*focusedWidget == widget)
    {
        if(focusableWidgets.size() == 1)
            focusedWidget = focusableWidgets.end();
        else if(focusedWidget == focusableWidgets.begin())
            focusedWidget = focusableWidgets.begin() + 1; 
        else
            focusedWidget -= 1;
    }

    focusableWidgets.erase(std::remove_if(focusableWidgets.begin(), focusableWidgets.end(),
                                        [widget](const Widget* w) { return w == widget; }),
                        focusableWidgets.end());
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
