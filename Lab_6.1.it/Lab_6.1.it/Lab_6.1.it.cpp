#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int* a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}
void Print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << a[i];
	cout << endl;
}
int Sum(int* a, const int size)
{
	int S = 0;
	for (int i = 0; i < size; i++)
		if (a[i] > 0 && a[i] % 2 == 0)
			S += a[i];
	return S;
}
void Replace(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		if (a[i] > 0 && a[i] % 2 == 0)
			a[i] = 0;
}
int Count(int* a, const int size)
{
	int k = 0;
	for (int i = 0; i < size; i++)
		if (a[i] > 0 && a[i] % 2 == 0)
			k++;
	return k;
}

int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	const int n = 25;
	int a[n];
	int Low = -20;
	int High = 30;

	Create(a, n, Low, High);
	Print(a, n);

	cout << "S = " << Sum(a, n) << endl;
	cout << "k = " << Count(a, n) << endl;

	Replace(a, n);
	Print(a, n);

	return 0;
}