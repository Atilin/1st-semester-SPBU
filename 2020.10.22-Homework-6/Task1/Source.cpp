#include<iostream>
#include <clocale>
#include "ArrayList.h"
using namespace std;

void printMenu()
{
	cout << "МЕНЮ" << endl;
	cout << "0 - Выйти из программы" << endl;
	cout << "1 - Добавить элемент, введенный с клавиатуры" << endl;
	cout << "2 - Вывести массив" << endl;
	cout << "3 - Проверить, является ли массив симметричным" << endl;
	cout << "4 - Циклически сдвинуть массив на n элементов. n>0 - сдвиг вправо, n<0 - сдвиг влево" << endl;
	cout << "5 - Проверить, может ли массив стать симметричным, если из него удалить один элемент" << endl;
}

void processChoice(int choice, ArrayList& list)
{
	switch (choice)
	{
	case 0:
	{
		cout << "Завершение работы программы" << endl;
	}
	break;
	case 1:
	{
		int element = 0;
		cout << "Введите элемент" << endl;
		cin >> element;
		list.add(element);
		cout << "Элемент добавлен" << endl;
	}
	break;
	case 2:
	{
		cout << list.toString() << endl;
	}
	break;
	case 3:
	{
		bool flag = true;
		for (int i = 0, j = list.length() - 1; i < list.length() / 2; ++i, --j)
		{
			if (list.get(i) != list.get(j))
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
			cout << "Массив симметричен" << endl;
		else
			cout << "Массив несимметричен" << endl;
	}
	break;
	case 4:
	{
		int n = 0;
		cout << "Введите n" << endl;
		cin >> n;
		n = n % list.length();
		if (n < 0)
		{
			n = list.length() + n;
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = list.length() - 1; j > 0; --j)
			{
				list.swap(j, j - 1);
			}
		}
		cout << list.toString() << endl;
	}
	break;
	case 5:
	{
		bool flag1 = false;
		for (int k = 0; k < list.length(); ++k)
		{
			bool flag = true;
			for (int i = 0, j = list.length() - 1; i < list.length() / 2; ++i, --j)
			{
				if (i == k)
				{
					i++;
					if (i == list.length())
					{
						break;
					}
				}
				if (j == k)
				{
					j--;
					if (j < 0)
					{
						break;
					}
				}
				if (list.get(i) != list.get(j))
				{
					flag = false;
					break;
				}
			}
			if (flag == true)
			{
				flag1 = true;
				break;
			}
		}
		if (flag1 == true)
			cout << "Массив может быть симметричным" << endl;
		else
			cout << "Массив не может быть симметричным" << endl;
	}
	break;
	}
}

int main(int argc, char* argv[])
{
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