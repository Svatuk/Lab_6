#include <iostream>
#include <iomanip>
#include <time.h>
#include <cmath>

using namespace std;

void Create(double* a, const int size, const int Low, const int High, int i) // формування масиву
{
	a[i] = Low + rand() % (High - Low) + rand() % 100 / 100.0;
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

void Print(double* a, const int size, int i) // вивід масиву
{
	cout << fixed << setprecision(2) << setw(8) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}

double Max(double* a, const int size, int i, double max)  // повертає максимальний елемент масиву
{
	if (a[i] > max)
		max = a[i];
	if (i < size - 1)
		return Max(a, size, i + 1, max);
	else
		return max;
}

int FindLastPositive(double* a, int i) // пошук останнього додатнього
{
	if (i < 0)
		return -1;
	if (a[i] > 0)
		return i;
	else
		return FindLastPositive(a, i - 1);
}

double SumBeforeLastPositive(double* a, int i, const int k) // сума до останнього додатнього
{
	if (i < k)
		return a[i] + SumBeforeLastPositive(a, i + 1, k);
	else
		return 0;
}

int Squeeze(double* a, const int size, const double A, const double B, int i, int j) // стискання масиву
{
	if (i < size)
		if (!(abs(a[i]) >= A && abs(a[i]) <= B))
		{
			a[j] = a[i];
			return Squeeze(a, size, A, B, i + 1, j + 1);
		}
		else
			return Squeeze(a, size, A, B, i + 1, j);
	else
		return j;
}

void FillZeros(double* a, const int size, int i) // заміна нулями елементів
{
	if (i < size)
	{
		a[i] = 0;
		FillZeros(a, size, i + 1);
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

	double* a = new double[n];
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	// 1.1
	cout << "Max = " << Max(a, n, 0, a[0]) << endl;
	// 1.2
	int k = FindLastPositive(a, n - 1);
	if (k == -1)
		cout << "NO last positive" << endl;
	else
		cout << "SumBeforeLastPositive = " << SumBeforeLastPositive(a, 0, k) << endl;
	// 2
	int squeeze = Squeeze(a, n, A, B, 0, 0);
	cout << "squeeze = " << squeeze << endl;
	FillZeros(a, n, squeeze);
	Print(a, n, 0);

	delete[] a;

	return 0;
}