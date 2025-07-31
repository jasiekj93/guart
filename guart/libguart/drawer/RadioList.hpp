#pragma once

/**
 * @file RadioList.hpp
 * @author Adrian Szczepanski
 * @date 09-07-2025
 */

#include <libguart/drawer/List.hpp>

namespace guart::drawer 
{
    class RadioList : public List 
    {
    public:
        explicit RadioList(Canvas& canvas);

    protected:
        void drawItem(const Drawable&, Output&, etl::string_view item, int index) const override;
    };

} 