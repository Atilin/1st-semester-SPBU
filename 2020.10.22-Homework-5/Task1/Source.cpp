#include <iostream>
#include <clocale>
#include<ctime>
#include "ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "МЕНЮ" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Добавить в список 10 случайных положительных двузначных чисел и вывести список" << endl;
	cout << "2 - Добавить в список 10 случайных отрицательных двузначных чисел и вывести список" << endl;
	cout << "3 - Поменять местами первый минимальный и последний максимальный элемент и вывести список" << endl;
	cout << "4 - Перемешать все элементы массива и вывести массив" << endl;
	cout << "5 - Заменить каждый отрицательный элемент массива на 0" << endl;
}

void processChoice(int choice, ArrayList& list)
{
	switch (choice)
	{
	case 0:
	{
		cout << "Чикибамбони\n";
	}
	break;
	case 1:
	{
		for (int i = 0; i < 10; ++i)
		{
			int t = rand() % 90 + 10;
			if (t < 0)
			{
				t = -t;
			}
			list.add(t);
		}
		cout << list.toString() << endl;
	}
	break;
	case 2:
	{
		for (int i = 0; i < 10; ++i)
		{
			int t = rand() % 90 + 10;
			if (t > 0)
			{
				t = -t;
			}
			list.add(t);
		}
		cout << list.toString() << endl;
	}
	break;
	case 3:
	{
		int min = list.get(0);
		//int indMin = 0;
		int max = list.get(0);
		//int indMax = 0;
		for (int i = 0; i < list.length(); ++i)
		{
			if (list.get(i) < min)
			{
				min = list.get(i);
				//indMin = i;
			}
			if (list.get(i) > max)
			{
				max = list.get(i);
				//indMax = i;
			}
		}

		int indMin = list.indexOf(min);
		int indMax = list.indexOf(max);
		list.swap(indMin, indMax);
		cout << list.toString();
	}
	break;
	case 4:
	{
		for (int i = 0; i < rand() % 30 + 10; ++i)
		{
			list.swap(rand() % list.length(), rand() % list.length());
		}
		cout << list.toString();
	}
	break;
	case 5:
	{
		for (int i = 0; i < list.length(); ++i)
		{
			if (list.get(i) < 0)
			{
				list.set(i, 0);
			}
		}
		cout << list.toString();
	}
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	ArrayList list;
	int choice = 0;
	do
	{
		system("cls");
		printMenu();
		cin >> choice;
		processChoice(choice, list);
		system("pause");
	} while (choice != 0);

	return EXIT_SUCCESS;
}