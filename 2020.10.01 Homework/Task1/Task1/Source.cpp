#include <iostream>
#include <clocale>
using namespace std;

void expandArray(int*& a, int& cap)
{
	cap += 10;
	int* temp = new int[cap] {0};
	for (int i = 0; i < cap; ++i)
	{
		temp[i] = a[i];
	}
	delete[] a;
	a = temp;
}

void addNumber(int*& a, int& cap, int& count)
{
	int x = 0;
	cin >> x;
	cout << endl;
	if (cap == count)
	{
		expandArray(a, cap);
	}
	a[count] = x;
	count++;
}

void outArray(int* a, int count)
{
	for (int i = 0; i < count; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

int indxMaxElement(int* a, int count)
{
	int result = 0;
	for (int i = 1; i < count; ++i)
	{
		if (a[i] > a[result])
		{
			result = i;
		}
	}
	return result;
}

int minElement(int* a, int count)
{
	int minimum = a[0];
	for (int i = 1; i < count; ++i)
	{
		if (a[i] < minimum)
		{
			minimum = a[i];
		}
	}
	return minimum;
}

int sum(int* a, int count)
{
	int sum = 0;
	for (int i = 0; i < count; ++i)
	{
		sum += a[i];
	}
	return sum;
}

void reverseArray(int* a, int count)
{
	for (int i = count - 1; i >= 0; --i)
	{
		cout << a[i] << ' ';
	}
	cout << endl << endl;
}

void check(int*& a, int& cap, int& count, int choice)
{
	switch (choice)
	{
	case 0:
	{
		cout << "Выход из программы\n\n";
		break;
	}
	case 1:
	{
		cout << "Введите число, которое хотите добавить\n\n";
		addNumber(a, cap, count);
		break;
	}
	case 2:
	{
		cout << "Массив а содержит следующие числа: ";
		outArray(a, count);
		break;
	}
	case 3:
	{
		cout << "Номер максимального элемента массива равен ";
		cout << indxMaxElement(a, count) << endl;
		break;
	}
	case 4:
	{
		cout << "Минимальный элемент массива равен ";
		cout << minElement(a, count) << endl;
		break;
	}
	case 5:
	{
		cout << "Сумма элементов массива равна ";
		cout << sum(a, count) << endl;
		break;
	}
	case 6:
	{
		cout << "Массив в обратном порядке: ";
		reverseArray(a, count);
		break;
	}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int cap = 10;
	int* a = new int[cap] {0};
	cout << "Введите элементы массива, завершите ввод элементом '0'\n\n";
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
			expandArray(a, cap);
		}
		a[count] = x;
		count++;
	}
	cout << endl;
	int choice = -1;
	while (choice != 0)
	{
		cout << "0 - Выход из программы \n1 - Добавить число в массив \n2 - Вывести массив на экран \n3 - Найти номер максимального элемента массива \n4 - Найти минимальный элемент массива \n5 - Посчитать сумму элементов массива \n6 - Вывести массив в обратном порядке\n";
		cout << "Введите цифру интересующей Вас функции\n\n";
		cin >> choice;
		check(a, cap, count, choice);
	}
	delete[] a;
	return 0;
}
