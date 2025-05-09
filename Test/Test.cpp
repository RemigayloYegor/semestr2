#include "pch.h"
#include "CppUnitTest.h"
#include "..\solver\Date.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
    TEST_CLASS(DateTest)
    {
    public:

        TEST_METHOD(Constructor_ValidDate_Success)
        {
            Date d(15, 3, 2022);
            Assert::AreEqual(d.GetDay(), 15);
            Assert::AreEqual(d.GetMonth(), 3);
            Assert::AreEqual(d.GetYear(), 2022);
        }

        TEST_METHOD(Constructor_InvalidDate_Fail)
        {
            auto func = []() { Date d(31, 2, 2022); };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(Operator_EqualEqual_Success)
        {
            Date d1(15, 3, 2022);
            Date d2(15, 3, 2022);
            Assert::IsTrue(d1 == d2);
        }


        TEST_METHOD(Operator_NotEqual_Success)
        {
            Date d1(15, 3, 2022);
            Date d2(16, 3, 2022);
            Assert::IsTrue(d1 != d2);
        }

        TEST_METHOD(Operator_LessThan_Success)
        {
            Date d1(15, 3, 2022);
            Date d2(16, 3, 2022);
            Assert::IsTrue(d1 < d2);
        }

        TEST_METHOD(Operator_GreaterThan_Success)
        {
            Date d1(17, 3, 2022);
            Date d2(16, 3, 2022);
            Assert::IsTrue(d1 > d2);
        }

        TEST_METHOD(AddDays_ValidDate_Success)
        {
            Date d(28, 2, 2020);
            Date result = d + 1;
            Assert::AreEqual(result.GetDay(), 29);
            Assert::AreEqual(result.GetMonth(), 2);
            Assert::AreEqual(result.GetYear(), 2020);
        }

        TEST_METHOD(SubtractDays_ValidDate_Success)
        {
            Date d(1, 3, 2020);
            Date result = d - 1;
            Assert::AreEqual(result.GetDay(), 29);
            Assert::AreEqual(result.GetMonth(), 2);
            Assert::AreEqual(result.GetYear(), 2020);
        }

        TEST_METHOD(Duration_ValidDates_Success)
        {
            Date d1(1, 1, 2020);
            Date d2(1, 1, 2021);
            std::string duration = d1.duration(d2);
            Assert::AreEqual(duration, std::string("1 year "));
        }

        TEST_METHOD(DayOfWeek_ValidDate_Success)
        {
            Date d(15, 3, 2022);
            Weekday wd = d.dayOfWeek();
            Assert::AreEqual(Date::weekDayToString(wd), std::string("Tuesday"));
        }

        TEST_METHOD(Tomorrow_ValidDate_Success)
        {
            Date d(31, 12, 2021);
            Date result = d.Tomorrow();
            Assert::AreEqual(result.GetDay(), 1);
            Assert::AreEqual(result.GetMonth(), 1);
            Assert::AreEqual(result.GetYear(), 2022);
        }

        TEST_METHOD(Yesterday_ValidDate_Success)
        {
            Date d(1, 1, 2022);
            Date result = d.Yesterday();
            Assert::AreEqual(result.GetDay(), 31);
            Assert::AreEqual(result.GetMonth(), 12);
            Assert::AreEqual(result.GetYear(), 2021);
        }
    };
}
