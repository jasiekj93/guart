#include "Widget.hpp"
#include "FocusController.hpp"
#include <algorithm>

using namespace guart;

Widget::Widget(const Point& position, etl::string_view label)
    : position(position)
    , label(label)
{
}

Point Widget::getPosition() const
{
    if(parent)
        return parent->getContentPosition() + position;
    else
        return position;
}

void Widget::dispose()
{
    if(onDispose)
        onDispose(*this, "");

   Parent::dispose();

    if(parent)
        parent->removeWidget(this);
}

bool guart::Widget::isFocused() const
{
    if(Parent::isFocused() == true)
        return true;
    else if(parent)
        return parent->isFocused();
    else
        return false;
}

void Widget::focusChangeCallback(bool isFocused)
{
    if(onFocus)
        onFocus(*this, "");

    if(parent and isFocused)
        parent->childFocusedCallback(this);

    invalidate();
}
