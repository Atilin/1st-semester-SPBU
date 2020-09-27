#include <iostream>
#include <algorithm>
using namespace std;

void expandArray(int count, int& cap, int*& a)
{
	if (count == cap)
	{
		cap += 10;
		int* temp = new int[cap];
		for (int i = 0; i < count; ++i)
		{
			temp[i] = a[i];
		}
		delete[] a;
		a = temp;
	}
}

int main()
{
	int cap = 10;
	int* a = new int[cap];
	cout << "Введите последовательность чисел, завершите ее нулем";
	int count = 0;
	while (true)
	{
		int x = 0;
		cin >> x;
		if (x == 0)
		{
			break;
		}
		expandArray(count, cap, a);
		a[count] = x;
		++count;
	}
	cout << endl;
	sort(a[0], a[count - 1]);
	int multiplication = 1;
	int sum = 0;
	int j = 0;
	for (int i = 1; i <= a[count - 1]; ++i)
	{
		multiplication *= i;
		while (i == a[j])
		{
			sum += multiplication;
			++j;
		}
	}
	cout << sum / count;
	return 0;
}