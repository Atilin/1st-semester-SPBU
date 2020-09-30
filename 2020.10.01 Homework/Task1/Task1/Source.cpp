#include <iostream>
#include <clocale>
using namespace std;

void menu()
{
	cout << "0 - Выход из программы \n";
	cout << "1 - Добавить число в массив \n";
	cout << "2 - Вывести массив на экран \n";
	cout << "3 - Найти номер максимального элемента массива \n";
	cout << "4 - Найти минимальный элемент массива \n";
	cout << "5 - Посчитать сумму элементов массива \n";
	cout << "6 - Вывести массив в обратном порядке\n";
	cout << "7 - Ввести массив\n";
	cout << "Введите цифру интересующей Вас функции\n\n";
}

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

void addNumber(int*& a, int& cap, int& count, int x)
{
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

void cinArray(int*& a, int& cap, int& count)
{
	while (true)
	{
		int x = 0;
		cin >> x;
		if (x == 0)
		{
			break;
		}
		addNumber(a, cap, count, x);
	}
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
		int x = 0;
		cin >> x;
		addNumber(a, cap, count, x);
		cout << endl;
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
	case 7:
	{
		cout << "Введите массив, завершите ввод нулем\n\n";
		cinArray(a, cap, count);
	}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int cap = 10;
	int* a = new int[cap] {0};
	int count = 0;
	int choice = -1;
	while (choice != 0)
	{
		menu();
		cin >> choice;
		check(a, cap, count, choice);
	}
	delete[] a;
	return 0;
}