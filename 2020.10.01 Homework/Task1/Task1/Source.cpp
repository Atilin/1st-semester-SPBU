#include <iostream>
#include <clocale>
#include <algorithm>
using namespace std;

int check(int*& a, int& count, int choice, int& cap)
{
	switch (choice)
	{
	case 0:
	{
		cout << "����� �� ���������\n\n";
		delete[] a;
		return 0;
	}
	case 1:
	{
		cout << "������� �����, ������� ������ ��������\n\n";
		int x = 0;
		cin >> x;
		cout << endl;
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
		a[count] = x;
		count++;
		break;
	}
	case 2:
	{
		cout << "������ � �������� ��������� �����: ";
		for (int i = 0; i < count; ++i)
		{
			cout << a[i] << ' ';
		}
		cout << endl;
		break;
	}
	case 3:
	{
		cout << "����� ������������� �������� ������� ����� ";
		int maximum = INT_MIN;
		int indxMax = -1;
		for (int i = 0; i < count; ++i)
		{
			if (a[i] > maximum)
			{
				maximum = a[i];
				indxMax = i;
			}
		}
		cout << indxMax + 1 << endl << endl;
		break;
	}
	case 4:
	{
		cout << "����������� ������� ������� ����� ";
		int minimum = INT_MAX;
		for (int i = 0; i < count; ++i)
		{
			if (a[i] < minimum)
			{
				minimum = a[i];
			}
		}
		cout << minimum << endl << endl;
		break;
	}
	case 5:
	{
		cout << "����� ��������� ������� ����� ";
		int sum = 0;
		for (int i = 0; i < count; ++i)
		{
			sum += a[i];
		}
		cout << sum << endl << endl;
		break;
	}
	case 6:
	{
		cout << "������ � �������� �������: ";
		for (int i = count - 1; i >= 0; --i)
		{
			cout << a[i] << ' ';
		}
		cout << endl << endl;
		break;
	}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int cap = 10;
	int* a = new int[cap];
	cout << "������� �������� �������, ��������� ���� ��������� '0'\n\n";
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
			cap += 10;
			int* temp = new int[cap];
			for (int i = 0; i < count; ++i)
			{
				temp[i] = a[i];
			}
			delete[] a;
			a = temp;
		}
		a[count] = x;
		count++;
	}
	cout << endl;
	int choice = -1;
	while (choice != 0)
	{
		cout << "0 - ����� �� ��������� \n1 - �������� ����� � ������ \n2 - ������� ������ �� ����� \n3 - ����� ����� ������������� �������� ������� \n4 - ����� ����������� ������� ������� \n5 - ��������� ����� ��������� ������� \n6 - ������� ������ � �������� �������\n";
		cout << "������� ����� ������������ ��� �������\n\n";
		cin >> choice;
		check(*&a, count, choice, cap);
	}
	delete[] a;
	return 0;
}