#include "Drawable.hpp"

using namespace guart;

void Drawable::invalidate() const
{
    if (drawer)
        drawer->draw(*this);
}