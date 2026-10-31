#include <iostream>
#include <iomanip>
#include <time.h>
#include <string>
using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i) // формування масиву
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}
void Print(int* a, const int size, int i) // вивід масиву
{
	cout << setw(6) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}

template <typename T>
void Print(T* a, const int size, int i) 
{
	cout << setw(6) << a[i];
	if (i < size - 1)
		Print<T>(a, size, i + 1);
	else
		cout << endl;
}


void Sort(int* a, const int size, int i) // метод вставки
{ // i - індекс початку невпорядкованої частини
	int tmp = a[i]; // вибрали елемент для вставки
	int j = 0; // пошук позиції вставки
	while (tmp < a[j])
		j++;
	for (int k = i - 1; k >= j; k--) // зсув
		a[k + 1] = a[k];
	a[j] = tmp; // вставка
	if (i < size - 1)
		Sort(a, size, i + 1); // рекурсивний виклик
}
template <typename T>
void Sort(T* a, const int size, int i) 
{ 
	T tmp = a[i]; 
	int j = 0;
	while (tmp < a[j])
		j++;
	for (int k = i - 1; k >= j; k--) 
		a[k + 1] = a[k];
	a[j] = tmp; 
	if (i < size - 1)
		Sort<T>(a, size, i + 1);
}

int main()
{
	srand((unsigned)time(NULL));
	const int n = 10;
	int a[n];
	int Low = -20;
	int High = 30;

	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	Sort(a, n, 1);
	Print(a, n, 0);

	cout << endl;

	int c[n];
	Create(c, n, Low, High, 0);
	Print<int>(c, n, 0);
	Sort<int>(c, n, 1);
	Print<int>(c, n, 0);

	cout << endl;

	double d[n] = { -7.7, 10.0, -3.3, 9.9, 6.7, 5.5, 1.1, 8.8, 4.3, -2.2 };
	Print<double>(d, n, 0);
	Sort<double>(d, n, 1);
	Print<double>(d, n, 0);

	cout << endl;

	const int m = 9;
	string s[m] = { "6 ", "8 ", "9 ", "7 ", "3 ", "4 ", "2 ", "5 ", "1 " };
	Print<string>(s, m, 0);
	Sort<string>(s, m, 1);
	Print<string>(s, m, 0);

	return 0;
}