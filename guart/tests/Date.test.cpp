/**
 * @file Date.test.cpp
 * @author Adrian Szczepanski
 * @date 2025-07-21
 */

#include <libguart/Date.hpp>

#include <CppUTest/TestHarness.h>

using namespace guart;

TEST_GROUP(DateTest)
{
	void setup()
	{

	}

	void teardown()
	{
		
	}
};

TEST(DateTest, Constructor)
{
    Date date(2000, 5, 3);
    CHECK_EQUAL(2000, date.getYear());
    CHECK_EQUAL(5, date.getMonth());
    CHECK_EQUAL(3, date.getDay());
}

TEST(DateTest, stringConstructor)
{
    Date date("2000-05-03");
    CHECK_EQUAL(2000, date.getYear());
    CHECK_EQUAL(5, date.getMonth());
    CHECK_EQUAL(3, date.getDay());
}

TEST(DateTest, addDay_one)
{
    Date date("2000-05-03");
    date += DateSpan(0, 0, 1);
    CHECK(Date("2000-05-04") == date);
}

TEST(DateTest, addDay_one_overlappingMonth)
{
    Date date("2000-05-31");
    date += DateSpan(0, 0, 1);
    CHECK(Date("2000-06-01") == date);
}

TEST(DateTest, removeDay_one)
{
    Date date("2000-05-03");
    date -= DateSpan(0, 0, 1);
    CHECK(Date("2000-05-02") == date);
}

TEST(DateTest, removeDay_one_overlappingMonth)
{
    Date date("2000-05-01");
    date -= DateSpan(0, 0, 1);
    CHECK(Date("2000-04-30") == date);
}

TEST(DateTest, removeDay_one_overlappingYear)
{
    Date date("2000-01-01");
    date -= DateSpan(0, 0, 1);
    CHECK(Date("1999-12-31") == date);
}

TEST(DateTest, removeDay_week_overlappingMonth)
{
    Date date("2000-05-01");
    date -= DateSpan(0, 0, 7);
    CHECK(Date("2000-04-24") == date);
}

TEST(DateTest, removeDay_week_march)
{
    Date date("2025-03-01");
    date -= DateSpan(0, 0, 7);
    CHECK(Date("2025-02-22") == date);
}