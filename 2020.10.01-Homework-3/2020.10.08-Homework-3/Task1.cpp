#include <iostream>
#include <clocale>
#include <algorithm>
//#include <ctime>

using namespace std;

void printMenu()
{
	cout << "МЕНЮ" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Ввести несколько элемнетов с клавиатуры" << endl;
	cout << "2 - Добавить в массив n случайных чисел в промежутке от a до b(n, a, b вводится с клавиатуры)" << endl;
	cout << "3 - Вывести массив на экран" << endl;
	cout << "4 - Поиск индекса элемента" << endl;
	cout << "5 - Добавление массива к массиву" << endl;
	cout << "6 - Объединение массивов" << endl;
	cout << "7 - Вставка элемента в массив" << endl;
	cout << "8 - Удаление нескольких подряд идущих элементов массива" << endl;
	cout << "9 - Поиск подпоследовательности" << endl;
}

int* initArray(int capacity = 10)
{
	int* result = new int[capacity + 2]{ 0 };
	result[1] = 10;
	result += 2;
	return result;
}

/// <summary>
/// Освобождение памяти из-под массива
/// </summary>
/// <param name="arr">Боги, ну указатель тут на какой-то элемент массива. Посмотрите несколькими строками выше</param>
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
/// Функция поиска первого вхождения элемента в массив.
/// </summary>
/// <param name="arr">Массив с элементами</param>
/// <param name="element">Искомый элемент</param>
/// <param name="start">Место начала поиска</param>
/// <returns>индекс первого найденного элемента или -1, если элемент не найден</returns>
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
/// Добавление массива элементов.
/// </summary>
/// <param name="arr">Массив, к которому добавляются элементы, расширяется только если не хватило места для элементов из добавляемого массива</param>
/// <param name="addedArr">Массив с добавляемыми элементами</param>
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
/// Объединение двух массивов в один.
/// {a1, a2, a3, a4, a5} {b1, b2, b3, b4, b5, b6, b7, b8}
/// </summary>
/// <param name="a">Массив, элементы которого должны стоять на четных местах в результирующем массиве</param>
/// <param name="b">Массив, элементы которого должны стоять на нечетных местах в результирующем массиве</param>
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
	cout << "Массивы объединены" << endl;
	//delete[] temp;
	//delete[] b;
}

///// <summary>
///// Извлечение элемента из массива. Все элементы, стоящие после него, должны быть сдвинуты на 1 влево.
///// </summary>
///// <param name="a">Массив с данными</param>
///// <param name="index">Индекс извлекаемого элемента</param>
///// <returns>элемент, стоявший под индексом index, если index был некорректен - вернуть -1</returns>
//int extract(int* a, int index)
//{
//
//}

/// <summary>
/// Вставка элемента в массив. У вставляемого элемента в итоге должен быть индекс index, все последующие элементы сдвигаются на 1 вправо.
/// </summary>
/// <param name="a">Модифицируемый массив</param>
/// <param name="index">Индекс вставленного элемента</param>
/// <param name="element">Значение элемента</param>
/// <returns>Возвращается 0, если все хорошо и индекс был корректен, 1 - если индес был некорректен</returns>
int insert(int*& a, int index, int element)
{
	if (index<0 || index >(*(a - 2)))
	{
		cout << "Некорректный индекс" << endl;
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
/// Удалить последовательность элементов из массива
/// </summary>
/// <param name="a">Модифицируемый массив</param>
/// <param name="startIndex">Начало удаляемого куска</param>
/// <param name="count">Количество удаялемых элементов</param>
/// <returns>0, если все прошло хорошо, 1, если входные данные были некорректными</returns>
int deleteGroup(int* a, int startIndex, int count = 1)
{
	if (startIndex < 0 || startIndex + count >* (a - 2))
	{
		cout << "Введены некорректные данные\n";
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
/// Поиск подпоследовательности в массиве
/// </summary>
/// <param name="a">Массив, в котором ищем подпоследовательность</param>
/// <param name="b">Искомая подпоследовательность</param>
/// <returns>Индекс начала подпоследовательности или -1, если таковой нет</returns>
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
		cout << "Чикибамбони\n";
		break;
	}
	case 1:
	{
		cout << "Введите поледовательность чисел, завершите её нулем" << endl;
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
		cout << "Введите n, min, max" << endl;
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
		cout << "Введите элемент, который хотите найти" << endl;
		int element = 0;
		cin >> element;
		cout << search(arr1, element);
		break;
	}
	case 5:
	{
		cout << "Введите массив, который хотите добавить к данному (ввод завершается нулем)" << endl;
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
		cout << "Введите массив, который хотите объединить с данным (ввод завершается нулем)" << endl;
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
		cout << "Введите индекс\n";
		cin >> index;
		cout << "Введите значение элемента\n";
		cin >> element;
		insert(arr1, index, element);
	}
	case 8:
	{
		cout << "Введите индекс элемента, с которого хотите начать удаление\n";
		int startIndex = 0;
		cin >> startIndex;
		cout << "Сколько элементов вы хотите удалить?\n";
		int count = 0;
		cin >> count;
		deleteGroup(arr1, startIndex, count);
		break;
	}
	case 9:
	{
		int element = 0;
		cout << "Введите массив (заверште ввод нулем)\n";
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