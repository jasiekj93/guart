#pragma once

/**
 * @file Date.hpp
 * @author Adrian Szczepanski
 * @date 21-07-2025
 */

#include <string>

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
        static const Date DEFAULT_DATE; 

        Date();
        Date(Year);
        Date(Year, Month);
        Date(Year, Month, Day);
        Date(std::string_view);

        inline Year getYear() const { return year; }
        inline Month getMonth() const { return month; }
        inline Day getDay() const { return day; }

        Date& operator+=(const DateSpan&);
        Date& operator-=(const DateSpan&);
        bool operator==(const Date&) const;

        std::string toString() const;
        
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
    std::string getMonthName(Month month);
}