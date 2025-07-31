#include "CheckList.hpp"
#include <libguart/widget/CheckList.hpp>
#include <libguart/Charset.hpp>

using namespace guart::drawer;

CheckList::CheckList(Canvas& canvas)
    : List(canvas)
{
}

void CheckList::drawItem(const Drawable& drawable, Output& out, etl::string_view item, int index) const
{
    auto& list = dynamic_cast<const guart::widget::CheckList&>(drawable);
    auto& selectedIndexes = list.getSelectedIndexes();

        // if (std::find(selectedIndexes.begin(), selectedIndexes.end(), index) != selectedIndexes.end())
        //     out << CHECK_BOX_CHECKED << ' ';
        // else
        //     out << CHECK_BOX_UNCHECKED << ' ';

        if (std::find(selectedIndexes.begin(), selectedIndexes.end(), index) != selectedIndexes.end())
            out << "[X] ";
        else
            out << "[ ] ";

        out << item;
}