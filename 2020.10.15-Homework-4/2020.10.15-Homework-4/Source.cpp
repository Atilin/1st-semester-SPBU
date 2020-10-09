#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "����" << endl;
	cout << "0 - ����� �� ���������" << endl;
	cout << "1 - ������� ������ �� �����" << endl;
	cout << "2 - �������� �������" << endl;
	cout << "3 - �������� ������� � �������" << endl;
	cout << "4 - ������� ������� �� �������" << endl;
	cout << "5 - ����� �������" << endl;
	cout << "6 - �������� ��������� ���������" << endl;
	cout << "7 - �������� ��������� ���������, ������� � ��������� �������" << endl;
	cout << "8 - ���� �� ������?\n";
	cout << "9 - �������� ������� �������� � ���������\n";
	cout << "10 - �������� ������\n";
	cout << "11 - ����� ������ ��������\n";
	cout << "12 - ����� ������� �� �������\n";
}

void processChoice(ArrayList& a, int choice)
{
	switch (choice)
	{
	case 0:
	{
		cout << "�����������\n";
	}
	break;
	case 1:
	{
		a.print();
	}
	break;
	case 2:
	{
		cout << "������� �������� ��������\n";
		int element = 0;
		cin >> element;
		a.add(element);
	}
	break;
	case 3:
	{
		int index = 0;
		int element = 0;
		cout << "������� ������, �� ����� �������� ������ �������� �������\n";
		cin >> index;
		cout << "������� �������� ��������\n";
		cin >> element;
		a.add(index, element);
	}
	break;
	case 4:
	{
		cout << "������� ������ ��������\n";
		int index = 0;
		cin >> index;
		a.remove(index);
	}
	break;
	case 5:
	{
		cout << "������� �������� ��������\n";
		int element = 0;
		cin >> element;
		a.contains(element);
	}
	break;
	case 6:
	{
		ArrayList list;
		cout << "������� ������������������, ��������� ���� �����\n";
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
		cout << "������� ������������������, ��������� ���� �����\n";
		int x = 0;
		cin >> x;
		while (x != 0)
		{
			list.add(x);
			cin >> x;
		}
		cout << "������� ������\n";
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
		cout << "������� ������ ������� ��������\n";
		int index1 = 0;
		cin >> index1;
		cout << "������� ������ ������� ��������\n";
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
		cout << "������� �������� ��������\n";
		int element;
		cin >> element;
		cout << a.indexOf(element) << endl;
	}
	break;
	case 12:
	{
		cout << "������� ������\n";
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