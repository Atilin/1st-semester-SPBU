#include <iostream>
#include <clocale>
using namespace std;

void expandArray(int*& a, int& cap, int& count)
{
	cap += 10;
	int* temp = new int[cap] {0};
	for (int i = 0; i < count; ++i)
	{
		temp[i] = a[i];
	}
	delete[] a;
	a = temp;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int cap = 10;
	int* a = new int[cap];
	cout << "Введите последовательность чисел, завершите ее нулем\n\n";
	int count = 0;
	while (true)
	{
		int x = 0;
		cin >> x;
		if (x == 0)
		{
			break;
		}
		if (count == cap)
		{
			expandArray(a, cap, count);
		}
		a[count] = x;
		++count;
	}
	cout << endl;
	double sum = 0;
	for (int i = 0; i < count; ++i)
	{
		int x = 1;
		for (int j = 2; j <= a[i]; ++j)
		{
			x *= j;
		}
		sum += x;
	}
	cout << sum/count;
	delete[] a;
	return 0;
}