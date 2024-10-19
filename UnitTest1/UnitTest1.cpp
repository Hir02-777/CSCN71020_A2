#include "pch.h"
#include "CppUnitTest.h"
#include "main.h"

extern "C" void setLength(int, int*);
extern "C" void setWidth(int, int*);
extern "C" int getPerimeter(int*, int*);
extern "C" int getArea(int*, int*);
extern "C" int getIntInput(const char*);


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleTests
{
    TEST_CLASS(RectangleTests)
    {
    public:

        TEST_METHOD(TestSetLength_ValidInput_SetsLengthCorrectly)
        {
            int length = 0;
            setLength(20, &length);
            Assert::AreEqual(20, length);
        }

        TEST_METHOD(TestSetLength_LowerBoundary_SetsLengthCorrectly)
        {
            int length = 0;
            setLength(1, &length);
            Assert::AreEqual(1, length);
        }

        TEST_METHOD(TestSetLength_UpperBoundary_SetsLengthCorrectly)
        {
            int length = 0;
            setLength(99, &length);
            Assert::AreEqual(99, length);
        }

        TEST_METHOD(TestSetLength_InvalidInput_DoesNotChangeLength)
        {
            int length = 50;
            setLength(100, &length);
            Assert::AreEqual(50, length);
        }

        TEST_METHOD(TestSetWidth_ValidInput_SetsWidthCorrectly)
        {
            int width = 0;
            setWidth(30, &width);
            Assert::AreEqual(30, width);
        }

        TEST_METHOD(TestSetWidth_LowerBoundary_SetsWidthCorrectly)
        {
            int width = 0;
            setWidth(1, &width);
            Assert::AreEqual(1, width);
        }

        TEST_METHOD(TestSetWidth_UpperBoundary_SetsWidthCorrectly)
        {
            int width = 0;
            setWidth(99, &width);
            Assert::AreEqual(99, width);
        }

        TEST_METHOD(TestSetWidth_InvalidInput_DoesNotChangeWidth)
        {
            int width = 50;
            setWidth(100, &width);
            Assert::AreEqual(50, width);
        }

        TEST_METHOD(TestGetPerimeter_ValidInputs_ReturnsCorrectValue)
        {
            int length = 5, width = 10;
            Assert::AreEqual(30, getPerimeter(&length, &width)); 
        }

        TEST_METHOD(TestGetArea_ValidInputs_ReturnsCorrectValue)
        {
            int length = 5, width = 10;
            Assert::AreEqual(50, getArea(&length, &width));
        }
    };
}
