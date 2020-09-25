#include <iostream>
#include <clocale>
using namespace std;

void expandArray(int count, int& cap, int*& a)
{
	if (count == cap)
	{
		cap *= 2;
		int* temp = new int[cap];
		for (int i = 0; i < count; ++i)
		{
			temp[i] = a[i];
		}
		delete[] a;
		a = temp;
	}
}

void addNumber(int& count, int& cap, int*& a)
{
	cout << "������� �����, ������� ������ ��������\n\n";
	int x = 0;
	cin >> x;
	cout << endl;
	expandArray(count, cap, a);
	a[count] = x;
	count++;
}

void outArray(int count, int*& a)
{
	cout << "������ � �������� ��������� �����: ";
	for (int i = 0; i < count; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

void indxMaxElement(int count, int*& a)
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
}

void minElement(int count, int*& a)
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
}

void sum(int count, int*& a)
{
	cout << "����� ��������� ������� ����� ";
	int sum = 0;
	for (int i = 0; i < count; ++i)
	{
		sum += a[i];
	}
	cout << sum << endl << endl;
}

void reverseArray(int count, int*& a)
{
	cout << "������ � �������� �������: ";
	for (int i = count - 1; i >= 0; --i)
	{
		cout << a[i] << ' ';
	}
	cout << endl << endl;
}

void check(int*& a, int& count, int choice, int& cap)
{
	switch (choice)
	{
	case 0:
	{
		cout << "����� �� ���������\n\n";
		break;
	}
	case 1:
	{
		addNumber(count, cap, *&a);
		break;
	}
	case 2:
	{
		outArray(count, *&a);
		break;
	}
	case 3:
	{
		indxMaxElement(count, *&a);
		break;
	}
	case 4:
	{
		minElement(count, *&a);
		break;
	}
	case 5:
	{
		sum(count, *&a);
		break;
	}
	case 6:
	{
		reverseArray(count, *&a);
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
		long long x = 0;
		cin >> x;
		if (x == 0)
		{
			break;
		}
		expandArray(count, cap, a);
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