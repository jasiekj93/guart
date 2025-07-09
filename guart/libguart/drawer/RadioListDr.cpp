#include "RadioList.hpp"
#include <libguart/widget/RadioList.hpp>
#include <libguart/Charset.hpp>

using namespace guart::drawer;

RadioList::RadioList(Canvas& canvas)
    : List(canvas)
{
}

void RadioList::drawItem(const Drawable& drawable, Output& out, std::string_view item, int index) const
{
    auto& list = dynamic_cast<const guart::widget::RadioList&>(drawable);

    if (list.getSelectedIndex() == index)
            out << RADIO_BUTTON_CHECKED << ' ';
        else
            out << RADIO_BUTTON_UNCHECKED << ' ';

        out << item;
}