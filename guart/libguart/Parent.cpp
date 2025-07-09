#include "Parent.hpp"
#include "Widget.hpp"

using namespace guart;

void Parent::addWidget(const std::shared_ptr<Widget>& widget)
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

void Parent::removeWidget(Widget* child)
{
    children.erase(std::remove_if(children.begin(), children.end(),
                                    [child](const std::shared_ptr<Widget>& w) { return w.get() == child; }),
                    children.end());

    invalidate();
}

void Parent::dispose()
{
    if(focusController)
        focusController->removeFocusable(this);

    while(not children.empty())
    {
        if(children.front())
            children.front()->dispose();
    }
}

void Parent::childFocusedCallback(Widget* child)
{
    if(not child)
        return;
    
    focusChangeCallback(true);

    auto it = std::find_if(children.begin(), children.end(),
                    [child](const std::shared_ptr<Widget>& w) { return w.get() == child; });

    if(it != children.end())
        std::rotate(it, it+1, children.end()); //move to the end, so it will be first on Z axis

    this->invalidate();
}

void Parent::invalidate() const
{
    Drawable::invalidate();

    for(auto& widget : children)
    {
        if(widget)
            widget->invalidate();
    }
}

void Parent::setDrawer(Drawer* d)
{
    Drawable::setDrawer(d);

    for(auto& widget : children)
    {
        if(widget)
            widget->setDrawer(d);
    }
}

void Parent::setFocusController(FocusController* controller)
{
    Focusable::setFocusController(controller);

    for(auto& widget : children)
    {
        if(widget)
            widget->setFocusController(controller);
    }
}
