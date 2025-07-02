#include "Widget.hpp"

using namespace guart;

Widget::Widget(const Point& position)
    : position(position)
    , parent(nullptr)
{
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

void Widget::addWidget(const std::shared_ptr<Widget>& widget)
{
    if (not widget)
        return;
    
    widget->setParent(this);

    if(drawer)
        widget->setDrawer(drawer);

    children.push_back(widget);
    
}