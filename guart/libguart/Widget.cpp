#include "Widget.hpp"
#include "FocusController.hpp"
#include <algorithm>

using namespace guart;

Widget::Widget(const Point& position, std::string_view label)
    : position(position)
    , label(label)
{
}

Widget::~Widget()
{
    if(isFocusable() and focusController)
        focusController->removeFocusableWidget(this);
}

void Widget::invalidate() const
{
    if(drawer)
        drawer->draw(*this);

    for(auto& widget : children)
    {
        if(widget)
            widget->invalidate();
    }
}

Point Widget::getPosition() const
{
    if(parent)
        return parent->getContentPosition() + position;
    else
        return position;
}

void Widget::setDrawer(Drawer* d)
{
    drawer = d;
    
    for(auto& child : children)
    {
        if(child)
            child->setDrawer(d);
    }
}

void Widget::setFocusController(FocusController* controller)
{
    if(not controller)
        return;

    focusController = controller;

    if(isFocusable())
        controller->addFocusableWidget(this);

    for(auto& child : children)
        child->setFocusController(controller);
}

void Widget::addWidget(const std::shared_ptr<Widget>& widget)
{
    if (not widget)
        return;
    
    widget->setParent(this);

    if(drawer)
        widget->setDrawer(drawer);

    if(focusController)
        widget->setFocusController(focusController);

    children.push_back(widget);
    
}

void Widget::removeWidget(Widget* child)
{
    children.erase(std::remove_if(children.begin(), children.end(),
                                    [child](const std::shared_ptr<Widget>& w) { return w.get() == child; }),
                    children.end());
    
    if(focusController)
        focusController->removeFocusableWidget(child);

    invalidate();
}

bool Widget::isFocused() const
{
    if(not focusController)
        return false;
    else
        return focusController->isWidgetFocused(this);
}

void Widget::remove()
{
    if(parent)
        parent->removeWidget(this);
}
