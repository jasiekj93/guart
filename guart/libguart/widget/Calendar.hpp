#pragma once

#include <libguart/Widget.hpp>
#include <libguart/Date.hpp>

namespace guart::widget
{
    class Calendar : public Widget
    {
    public:
        Calendar(const Point& position, const Date& = {2000, 1, 1});

        inline auto getDate() const { return date; }
        inline void setDate(const Date& d) { date = d; }

        inline etl::string_view getType() const override { return "Calendar"; }
        inline bool isFocusable() const override { return true; }

        void processKey(const etl::string_view& input) override;

    private:
        Date date;
    };
}