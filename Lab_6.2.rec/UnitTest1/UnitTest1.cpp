#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab_6.2.rec\Lab_6.2.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[5] = { -5, 2, -3, 6, 7 };      // непарні: -5, -3, 7
			double t = Sum(a, 5, 0);
			Assert::AreEqual(-1.0, t, 0.0001);
		}
	};
}
