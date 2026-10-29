#include <iostream>
#include <iomanip>
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
		cout << setw(4) << a[i];
	cout << endl;
}
double Average(int* a, const int size) // функція яка обчислює середнє арифметичне непарних елементів
{
	double S = 0;
	int t = 0;
	for (int i = 0; i < size; i++)
		if (a[i] % 2 != 0)
		{
			S += a[i];
			t++;
		}
	if (t == 0)
		return 0;   // непарних елементів немає
	return S / t;
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

	cout << "Arithmetic mean = " << Average(a, n) << endl;
	
	return 0;
}