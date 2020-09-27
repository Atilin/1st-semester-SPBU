#include <iostream>
#include <clocale>
using namespace std;

void expandArray(int*& a, int& cap, int& count)
{
	if (count == cap)
	{
		cap += 10;
		int* temp = new int[cap] {0};
		for (int i = 0; i < count; ++i)
		{
			temp[i] = a[i];
		}
		delete[] a;
		a = temp;
	}
}

void outArray(int*& a, int& count)
{
	if (count == 0)
	{
		cout << "EMPTY";
	}
	else
	{
		for (int i = 0; i < count; ++i)
		{
			cout << a[i] << ' ';
		}
	}
	cout << endl << endl;
}

void menu()
{
	cout << "0 - Выход из программы\n";
	cout << "1 - Добавить в массив n случайных чисел в промежутке от a до b\n";
	cout << "2 - Развернуть массив\n";
	cout << "3 - Поменять элементы массива местами в парах.Если число элементов нечетно, последний элемент остается на своем месте\n";
	cout << "4 - Циклический сдвиг вправо на 1\n";
	cout << "5 - Развернуть две половинки массива. n - номер элемента, разделяющего половинки\n";
	cout << "6 - Вывод массива\n";
	cout << "Введите цифру интересующей вас функции\n\n";
}

void addRandNumbers(int*& a, int& cap, int& count)
{
	int l = 0;
	int r = 0;
	int n = 0;
	cout << "Сколько случайных чисел вы хотите ввести?\n";
	cin >> n;
	cout << "Чему может равняться наименьший элемент?\n";
	cin >> l;
	cout << "Чему может равняться наибольший элемент?\n";
	cin >> r;
	for (int i = 0; i < n; ++i)
	{
		expandArray(a, cap, count);
		a[count] = rand() % (r - l + 1) + l;
		++count;
	}
}

void reverseArray(int*& a, int& count) //без передачи массива не знаю как сделать
{
	int j = count - 1;
	for (int i = 0; i < count / 2; ++i)
	{
		int x = 0;
		x = a[i];
		a[i] = a[j];
		a[j] = x;
		--j;
	}
}

void swapElements(int*& a, int& count)
{
	for (int i = 0; i < count / 2 * 2; i += 2)
	{
		int x = 0;
		x = a[i];
		a[i] = a[i + 1];
		a[i + 1] = x;
	}
}

void shiftBy1(int*& a, int& cap, int& count)
{
	int x = 0;
	x = a[count - 1];
	for (int i = count - 1; i > 0; --i)
	{
		a[i] = a[i - 1];
	}
	a[0] = x;
}

void reverseHalf(int*& a, int& cap, int& count)
{
	cout << "Введите 'n'\n";
	int n = 0;
	cin >> n;
	int j = n - 1;
	for (int i = 0; i < n / 2; ++i)
	{
		int x = 0;
		x = a[i];
		a[i] = a[j];
		a[j] = x;
		--j;
	}
	j = count - 1;
	for (int i = n; i < n + (count - n) / 2; ++i)
	{
		int x = 0;
		x = a[i];
		a[i] = a[j];
		a[j] = x;
		--j;
	}
}

void check(int*& a, int& cap, int& count, int& choice)
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
		addRandNumbers(a, cap, count);
		break;
	}
	case 2:
	{
		reverseArray(a, count);
		break;
	}
	case 3:
	{
		swapElements(a, count);
		break;
	}
	case 4:
	{
		shiftBy1(a, cap, count);
		break;
	}
	case 5:
	{
		reverseHalf(a, cap, count);
		break;
	}
	case 6:
	{
		outArray(a, count);
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
		expandArray(a, cap, count);
		a[count] = x;
		count++;
	}
	cout << endl << endl;
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