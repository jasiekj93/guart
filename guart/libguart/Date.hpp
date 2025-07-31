#pragma once

/**
 * @file Date.hpp
 * @author Adrian Szczepanski
 * @date 21-07-2025
 */

#ifndef GUART_DATE_DATESTRING_LIMIT
#define GUART_DATE_DATESTRING_LIMIT 10
#endif

#include <etl/string.h>

namespace guart
{
    using Year = int;
    using Month = int;
    using Day = int;

    struct DateSpan
    {
        Year years = 0;
        Month months = 0;
        Day days = 0;

        DateSpan() = default;

        DateSpan(Year y, Month m, Day d)
            : years(y), months(m), days(d) {}
    };

    class Date
    {
    public:
        static constexpr size_t STRING_LIMIT = GUART_DATE_DATESTRING_LIMIT;
        using String = etl::string<STRING_LIMIT>;

        static const Date DEFAULT_DATE; 

        Date();
        Date(Year);
        Date(Year, Month);
        Date(Year, Month, Day);
        Date(etl::string_view);

        inline Year getYear() const { return year; }
        inline Month getMonth() const { return month; }
        inline Day getDay() const { return day; }

        Date& operator+=(const DateSpan&);
        Date& operator-=(const DateSpan&);
        bool operator==(const Date&) const;

        String toString() const;

    protected:
        void normalizeDate();
        void normalizeDay();
        void normalizeMonth();

    private:
        Year year;
        Month month;
        Day day;
    };

    bool isLeapYear(Year);
    int getWeekday(const Date& date);
    int getDaysInMonth(Month, Year);
    Date::String getMonthName(Month month);
}