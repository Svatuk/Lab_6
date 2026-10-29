#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab_6.2.it\\Lab_6.2.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[5] = { 1, 2, 3, 4, 5 };        // непарні: 1, 3, 5
			double t = Average(a, 5);
			Assert::AreEqual(3.0, t, 0.0001);
		}
	};
}
