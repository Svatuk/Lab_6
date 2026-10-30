#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;

void Create(int* a, const int size, const int Low, const int High) // створення масиву
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}

void Print(int* a, const int size) // вивід масиву
{
	for (int i = 0; i < size; i++)
		cout << setw(6) << a[i];
	cout << endl;
}

template <typename T>
void Print(T* a, const int size) 
{
	for (int i = 0; i < size; i++)
		cout << setw(6) << a[i];
	cout << endl;
}


void Sort(int* a, const int size) // метод вставки
{
	for (int i = 1; i < size; i++) // індекс початку невпорядкованої частини
	{
		int tmp = a[i]; // вибрали елемент для вставки
		int j = 0; // пошук позиції вставки
		while (tmp < a[j])
			j++;
		for (int k = i - 1; k >= j; k--) // зсув
			a[k + 1] = a[k];
		a[j] = tmp; // вставка
	}
}

template <typename T>
void Sort(T* a, const int size)
{
	for (int i = 1; i < size; i++)
	{
		T tmp = a[i];
		int j = 0;
		while (tmp < a[j])
			j++;
		for (int k = i - 1; k >= j; k--)
			a[k + 1] = a[k];
		a[j] = tmp;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	const int n = 20;
	int a[n];
	int Low = -20;
	int High = 30;

	Create(a, n, Low, High);
	Print(a, n);
	Sort(a, n);
	Print(a, n);

	cout << endl;

	int c[n];
	Create(c, n, Low, High);
	Print<int>(c, n);
	Sort<int>(c, n);
	Print<int>(c, n);

	cout << endl;

	double b[n] = { -7.7, 10.0, -3.3, 9.9, 6.7, 5.5, 1.1, 8.8, 4.3, -2.2, -6.7, -5.3, -10, 3.4, -9.7, 0.5, 7.7, -1.2, 2.4, -4.7};
	Print<double>(b, n);
	Sort<double>(b, n);
	Print<double>(b, n);

	cout << endl;

	const int m = 9;
	string d[m] = { "6 ", "8 ", "9 ", "7 ", "3 ", "4 ", "2 ", "5 ", "1 " };
	Print<string>(d, m);
	Sort<string>(d, m);
	Print<string>(d, m);

	return 0;
}

