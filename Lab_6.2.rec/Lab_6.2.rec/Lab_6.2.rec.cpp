#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int* a, const int size, const int Low, const int High, int i) // формування масиву
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}
void Print(int* a, const int size, int i) // вивід масиву
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}
double Sum(int* a, const int size, int i) // сума всіх не парних елементів
{
	if (i < size)
	{
		if (a[i] % 2 != 0)
			return a[i] + Sum(a, size, i + 1);
		else
			return Sum(a, size, i + 1);
	}
	else
		return 0;
}

int Count(int* a, const int size, int i) // кількість непарних елементів
{
	if (i < size)
	{
		if (a[i] % 2 != 0)
			return 1 + Count(a, size, i + 1);
		else
			return Count(a, size, i + 1);
	}
	else
		return 0;
}

double Average(int* a, const int size) // середнє арифметичне не парних елементів
{
	int k = Count(a, size, 0);
	if (k == 0)
		return 0; // якщо непарних елементів немає
	return Sum(a, size, 0) / k;
}

int main()
{
	srand((unsigned)time(NULL));
	const int n = 25;
	int a[n];
	int Low = -20;
	int High = 30;

	Create(a, n, Low, High, 0);
	Print(a, n, 0);

	cout << "Arithmetic mean = " << Average(a, n) << endl;

	return 0;
}