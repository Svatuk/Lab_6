#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab_6.4.it\\Lab_6.4.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double a[5] = { -6.4, 4.6, 8.2, -2.1, 9.3 };
			double t = Max(a, 5);
			Assert::AreEqual(9.3, t, 0.001);
		}
	};
}
