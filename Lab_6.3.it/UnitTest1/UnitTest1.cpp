#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab_6.3.it\Lab_6.3.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[6] = { 3, -1, 7, 3, 0, -5 };
			int e[6] = { 7, 3, 3, 0, -1, -5 };         // очікуваний результат
			Sort(a, 6);
			for (int i = 0; i < 6; i++)
				Assert::AreEqual(e[i], a[i]);
		}
	};
}
