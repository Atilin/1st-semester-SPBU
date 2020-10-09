#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "МЕНЮ" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Вывести массив на экран" << endl;
	cout << "2 - Добавить элемент" << endl;
	cout << "3 - Добавить элемент в позицию" << endl;
	cout << "4 - Удалить элемент по индексу" << endl;
	cout << "5 - Найти элемент" << endl;
	cout << "6 - Добавить несколько элементов" << endl;
	cout << "7 - Добавить несколько элементов, начиная с некоторой позиции" << endl;
	cout << "8 - Пуст ли массив?\n";
	cout << "9 - Поменять местами элементы с индексами\n";
	cout << "10 - Очистить массив\n";
	cout << "11 - Найти индекс элемента\n";
	cout << "12 - Найти элемент по индексу\n";
}

void processChoice(ArrayList& a, int choice)
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
		a.print();
	}
	break;
	case 2:
	{
		cout << "Введите значение элемента\n";
		int element = 0;
		cin >> element;
		a.add(element);
	}
	break;
	case 3:
	{
		int index = 0;
		int element = 0;
		cout << "Введите индекс, на место которого хотите вставить элемент\n";
		cin >> index;
		cout << "Введите значение элемента\n";
		cin >> element;
		a.add(index, element);
	}
	break;
	case 4:
	{
		cout << "Введите индекс элемента\n";
		int index = 0;
		cin >> index;
		a.remove(index);
	}
	break;
	case 5:
	{
		cout << "Введите значение элемента\n";
		int element = 0;
		cin >> element;
		a.contains(element);
	}
	break;
	case 6:
	{
		ArrayList list;
		cout << "Введите последовательность, завершите ввод нулем\n";
		int x = 0;
		cin >> x;
		while (x != 0)
		{
			list.add(x);
			cin >> x;
		}
		a.addAll(list);
	}
	break;
	case 7:
	{
		ArrayList list;
		cout << "Введите последовательность, завершите ввод нулем\n";
		int x = 0;
		cin >> x;
		while (x != 0)
		{
			list.add(x);
			cin >> x;
		}
		cout << "Введите индекс\n";
		int index = 0;
		cin >> index;
		a.addAll(index, list);
	}
	break;
	case 8:
	{
		a.isEmpty();
	}
	break;
	case 9:
	{
		cout << "Введите индекс первого элемента\n";
		int index1 = 0;
		cin >> index1;
		cout << "Введите индекс второго элемента\n";
		int index2 = 0;
		cin >> index2;
		a.swap(index1, index2);
	}
	break;
	case 10:
	{
		a.clear();
	}
	break;
	case 11:
	{
		cout << "Введите значение элемента\n";
		int element;
		cin >> element;
		cout << a.indexOf(element) << endl;
	}
	break;
	case 12:
	{
		cout << "Введите индекс\n";
		int index = 0;
		cin >> index;
		cout << a.get(index) << endl;
	}
	break;
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	ArrayList a;

	int choice = 0;
	do
	{
		system("cls");
		printMenu();
		cin >> choice;
		processChoice(a, choice);
		system("pause");
	} while (choice != 0);

	return EXIT_SUCCESS;
}
