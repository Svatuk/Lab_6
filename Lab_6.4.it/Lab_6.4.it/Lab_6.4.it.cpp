#include <iostream>
#include <iomanip>
#include <time.h>
#include <cmath>
using namespace std;

void Create(double* a, const int size, const int Low, const int High) // створення масиву
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low) + rand() % 100 / 100.0;
}

void Print(double* a, const int size) // вивід масиву
{
	for (int i = 0; i < size; i++)
		cout << fixed << setprecision(2) << setw(8) << a[i];
	cout << endl;
}

double Max(double* a, const int size) // повертає максимальний елемент масиву
{
	double max = a[0];
	for (int i = 1; i < size; i++)
	{
		if (a[i] > max)
			max = a[i];
		
	}
	return max;
}

int FindLastPositive(double* a, const int size) // пошук останнього додатнього
{
	for (int i = size - 1; i != -1; i--)
	{
		if (a[i] > 0)
			return i;
	}
	return -1;
}

double SumBeforeLastPositive(double* a, const int k) // сума до останнього додатнього
{
	double sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum += a[i];
	}
	return sum;
}

int Squeeze(double* a, const int size, const double A, const double B) // стискання масиву
{
	int j = 0; // індекс елементу на який треба перенести елемент і який підходить за умовою в масиві 
	for (int i = 0; i < size; i++)
	{
		if (!(abs(a[i]) >= A && abs(a[i]) <= B))
		{
			a[j] = a[i];
			j++;
		}
	
	}
	return j;
}

void FillZeros(double* a, const int size, const int squeeze) 
{
	for (int i = squeeze; i < size; i++)
	{
		a[i] = 0;
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int Low = -100;
	int High = 100;
	
	int n;
	double A;
	double B;
	cout << "n = "; cin >> n;
	cout << "a = "; cin >> A;
	cout << "b = "; cin >> B;

	double *a = new double[n];
	Create(a, n, Low, High);
	Print(a, n);
	// 1.1 
	cout << "Max = " << Max(a, n) << endl;

	// 1.2
	int k = FindLastPositive(a, n);
	if (k == -1)
		cout << "NO last positive" << endl;
	else
		cout << "SumBeforeLastPositive = " << SumBeforeLastPositive(a, k) << endl;

	// 2
	int squeeze = Squeeze(a, n, A, B);
	cout << "Squeeze = " << squeeze << endl;
	FillZeros(a, n, squeeze);
	Print(a, n);

	delete[] a;

	return 0;
}