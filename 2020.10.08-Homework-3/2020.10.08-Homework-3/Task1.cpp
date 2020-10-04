#include <iostream>
#include <clocale>
#include <algorithm>
//#include <ctime>

using namespace std;

void printMenu()
{
	cout << "����" << endl;
	cout << "0 - ����� �� ���������" << endl;
	cout << "1 - ������ ��������� ��������� � ����������" << endl;
	cout << "2 - �������� � ������ n ��������� ����� � ���������� �� a �� b(n, a, b �������� � ����������)" << endl;
	cout << "3 - ������� ������ �� �����" << endl;
	cout << "4 - ����� ������� ��������" << endl;
	cout << "5 - ���������� ������� � �������" << endl;
	cout << "6 - ����������� ��������" << endl;
	cout << "7 - ������� �������� � ������" << endl;
	cout << "8 - �������� ���������� ������ ������ ��������� �������" << endl;
	cout << "9 - ����� ���������������������" << endl;
}

int* initArray(int capacity = 10)
{
	int* result = new int[capacity + 2]{ 0 };
	result[1] = 10;
	result += 2;
	return result;
}

/// <summary>
/// ������������ ������ ��-��� �������
/// </summary>
/// <param name="arr">����, �� ��������� ��� �� �����-�� ������� �������. ���������� ����������� �������� ����</param>
void deleteArray(int* arr)
{
	delete[] arr;
}

void expandArray(int*& arr1)
{
	int newCapacity = *(arr1 - 1) + 10;
	int* temp = new int[newCapacity] { 0 };
	temp += 2;
	for (int i = -2; i < *(arr1 - 2) + 2; ++i)
	{
		*(temp + i) = *(arr1 + i);
	}
	delete[] arr1;
	arr1 = temp;
	*(arr1 - 1) = newCapacity;
	temp -= 2;
	delete[] temp;
}

void addElement(int*& arr1, int element)
{
	if (*(arr1 - 1) == *(arr1 - 2))
	{
		expandArray(arr1);
	}
	*(arr1 + *(arr1 - 2)) = element;
	*(arr1 - 2) += 1;
}

void addRandomElements(int*& arr1, int n, int min, int max)
{
	for (int i = 0; i < n; ++i)
	{
		addElement(arr1, rand() % (max - min + 1) + min);
	}
}

void printArray(int* arr1)
{
	cout << "[" << arr1[-2] << "/" << arr1[-1] << "] {";
	for (int i = 0; i < arr1[-2]; ++i)
	{
		cout << *(arr1 + i) << (i == arr1[-2] - 1 ? "}\n" : ", ");
	}
}

/// <summary>
/// ������� ������ ������� ��������� �������� � ������.
/// </summary>
/// <param name="arr">������ � ����������</param>
/// <param name="element">������� �������</param>
/// <param name="start">����� ������ ������</param>
/// <returns>������ ������� ���������� �������� ��� -1, ���� ������� �� ������</returns>
int search(int* arr1, int element, int start = 0)
{
	int output = -1;
	for (int i = start; i < *(arr1 - 2); ++i)
	{
		if (*(arr1 + i) == element)
		{
			output = i;
			break;
		}
	}
	return output;
}

/// <summary>
/// ���������� ������� ���������.
/// </summary>
/// <param name="arr">������, � �������� ����������� ��������, ����������� ������ ���� �� ������� ����� ��� ��������� �� ������������ �������</param>
/// <param name="addedArr">������ � ������������ ����������</param>
void add(int*& arr1, int* arr2)
{
	if (*(arr1 - 2) + *(arr2 - 2) > * (arr2 - 1))
	{
		expandArray(arr1);
	}
	for (int i = 0; i < *(arr2 - 1); ++i)
	{
		*(arr1 + *(arr1 - 2) + i) = *(arr2 + i);
	}
}

/// <summary>
/// ����������� ���� �������� � ����.
/// {a1, a2, a3, a4, a5} {b1, b2, b3, b4, b5, b6, b7, b8}
/// </summary>
/// <param name="a">������, �������� �������� ������ ������ �� ������ ������ � �������������� �������</param>
/// <param name="b">������, �������� �������� ������ ������ �� �������� ������ � �������������� �������</param>
/// <returns>
/// result[-1] = a[-2] + b[-2]
/// {a1, b1, a2, b2, a3, b3, a4, b4, a5, b5, b6, b7, b8}
///</returns>
void unify(int*& a, int*& b)
{
	int newCapacity = *(a - 2) + *(b - 2);
	int* temp = new int[newCapacity + 2]{ 0 };
	*(temp) = *(a - 2) + *(b - 2);
	*(temp + 1) = *(a - 2) + *(b - 2);
	temp += 2;
	int i = 0;
	int j = 0;
	if (*(a - 2) > * (b - 2))
	{
		for (i; i < *(b - 2); ++i)
		{
			*(temp + j) = *(a + i);
			*(temp + j + 1) = *(b + i);
			j += 2;

		}
		for (i; i < *(a - 2); ++i)
		{
			*(temp + j) = *(a + i);
			j++;
		}

	}
	else
	{
		for (i; i < *(a - 2); ++i)
		{
			*(temp + j) = *(a + i);
			*(temp + j + 1) = *(b + i);
			j += 2;
		}
		for (i; i < *(b - 2); ++i)
		{
			*(temp + j) = *(b + i);
			j++;
		}
	}
	a = temp;
	cout << "������� ����������" << endl;
	//delete[] temp;
	//delete[] b;
}

///// <summary>
///// ���������� �������� �� �������. ��� ��������, ������� ����� ����, ������ ���� �������� �� 1 �����.
///// </summary>
///// <param name="a">������ � �������</param>
///// <param name="index">������ ������������ ��������</param>
///// <returns>�������, �������� ��� �������� index, ���� index ��� ����������� - ������� -1</returns>
//int extract(int* a, int index)
//{
//
//}

/// <summary>
/// ������� �������� � ������. � ������������ �������� � ����� ������ ���� ������ index, ��� ����������� �������� ���������� �� 1 ������.
/// </summary>
/// <param name="a">�������������� ������</param>
/// <param name="index">������ ������������ ��������</param>
/// <param name="element">�������� ��������</param>
/// <returns>������������ 0, ���� ��� ������ � ������ ��� ���������, 1 - ���� ����� ��� �����������</returns>
int insert(int*& a, int index, int element)
{
	if (index<0 || index >(*(a - 2)))
	{
		cout << "������������ ������" << endl;
		return 1;
	}
	if (*(a - 2) + 1 == *(a - 1))
	{
		expandArray(a);
	}
	for (int i = *(a - 2); i > index; --i)
	{
		*(a + i) = *(a + i - 1);
	}
	*(a + index) = element;
	*(a - 2) += 1;
	return 0;
}

/// <summary>
/// ������� ������������������ ��������� �� �������
/// </summary>
/// <param name="a">�������������� ������</param>
/// <param name="startIndex">������ ���������� �����</param>
/// <param name="count">���������� ��������� ���������</param>
/// <returns>0, ���� ��� ������ ������, 1, ���� ������� ������ ���� �������������</returns>
int deleteGroup(int* a, int startIndex, int count = 1)
{
	if (startIndex < 0 || startIndex + count >* (a - 2))
	{
		cout << "������� ������������ ������\n";
		return 1;
	}
	for (int i = startIndex; i + count < *(a - 2); ++i)
	{
		*(a + i) = *(a + i + count);
	}
	*(a - 2) -= count;
	return 0;
}

/// <summary>
/// ����� ��������������������� � �������
/// </summary>
/// <param name="a">������, � ������� ���� ���������������������</param>
/// <param name="b">������� ���������������������</param>
/// <returns>������ ������ ��������������������� ��� -1, ���� ������� ���</returns>
int subSequence(int* a, int* b)
{
	for (int i = 0; i < *(a - 2) - *(b - 2) + 1; ++i)
	{
		int k = 0;
		for (int j = 0; j < *(b - 2); ++j)
		{
			if (*(a + i + j) == *(b + j))
			{
				k++;
			}
		}
		if (k == *(b - 2))
		{
			return i;
		}
	}
	return -1;
}


void processChoice(int*& arr1, int*& arr2, int choice)
{
	switch (choice)
	{
	case 0:
	{
		cout << "�����������\n";
		break;
	}
	case 1:
	{
		cout << "������� ����������������� �����, ��������� � �����" << endl;
		int element = 0;
		while (1)
		{
			cin >> element;
			if (element == 0)
			{
				break;
			}
			addElement(arr1, element);

		}
		break;
	}
	case 2:
	{
		cout << "������� n, min, max" << endl;
		int n = 0;
		int min = 0;
		int max = 0;
		cin >> n >> min >> max;
		addRandomElements(arr1, n, min, max);
		break;
	}
	case 3:
	{
		printArray(arr1);
		break;
	}
	case 4:
	{
		cout << "������� �������, ������� ������ �����" << endl;
		int element = 0;
		cin >> element;
		cout << search(arr1, element);
		break;
	}
	case 5:
	{
		cout << "������� ������, ������� ������ �������� � ������� (���� ����������� �����)" << endl;
		int element = 0;
		while (1)
		{
			cin >> element;
			if (element == 0)
			{
				break;
			}
			addElement(arr1, element);
		}
		break;
	}
	case 6:
	{
		cout << "������� ������, ������� ������ ���������� � ������ (���� ����������� �����)" << endl;
		int element = 0;
		while (1)
		{
			cin >> element;
			if (element == 0)
			{
				break;
			}
			addElement(arr2, element);
		}
		unify(arr1, arr2);
		break;
	}
	case 7:
	{
		int index = 0;
		int element = 0;
		cout << "������� ������\n";
		cin >> index;
		cout << "������� �������� ��������\n";
		cin >> element;
		insert(arr1, index, element);
	}
	case 8:
	{
		cout << "������� ������ ��������, � �������� ������ ������ ��������\n";
		int startIndex = 0;
		cin >> startIndex;
		cout << "������� ��������� �� ������ �������?\n";
		int count = 0;
		cin >> count;
		deleteGroup(arr1, startIndex, count);
		break;
	}
	case 9:
	{
		int element = 0;
		cout << "������� ������ (�������� ���� �����)\n";
		while (1)
		{
			cin >> element;
			if (element == 0)
			{
				break;
			}
			addElement(arr2, element);
		}
		cout << subSequence(arr1, arr2) << endl;
		break;
	}
	}
}

int main()
{
	//srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int* a = initArray(10);
	int* b = initArray(10);

	int choice = 0;
	do
	{
		//system("cls");
		printMenu();
		cin >> choice;
		processChoice(a, b, choice);
		//system("pause");
	} while (choice != 0);

	deleteArray(a);
	deleteArray(b);
	return EXIT_SUCCESS;
}