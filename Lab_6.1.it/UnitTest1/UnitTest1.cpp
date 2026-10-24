#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.1.it/Lab_6.1.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[10] = { 5, -10, 10, 18, 7, 8, 0, -4, 3, 22 };
			int S = Sum(a, 10);
			Assert::AreEqual(58, S);      // 10 + 18 + 8 + 22 = 58
		}
	};
}
