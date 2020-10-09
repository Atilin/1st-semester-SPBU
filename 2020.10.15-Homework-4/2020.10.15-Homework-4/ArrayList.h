#pragma once
#include <iostream>

using namespace std;

struct ArrayList 
{
	int count;
	int capacity;
	int* data;

	ArrayList();
	ArrayList(int capacity);
	~ArrayList();

	//методы
	/// <summary>
	/// добавляет элемент в конец
	///</summary>
	/// <param name="element">добавляемый элемент</param>
	/// <returns></returns>
	bool add(int element);
	/// <summary>
	/// добавляет элемент в позицию index, все последующие элементы сдвигаются на 1 вправо
	/// </summary>
	/// <param name="index">индекс вставляемого элемента</param>
	/// <param name="element">вставляемый элемент</param>
	/// <returns>true, если все прошло хорошо, false - если возникли проблемы</returns>
	bool add(int index, int element);


	/// /// добавляет все элементы из списка list в конец
	///
	/// добавляемый список
	/// true, если получилось добавить, false - если не получилось
	bool addAll(ArrayList& list);

	/// /// добавляет все элементы из списка list, начиная с позиции index.
	/// все последующие элементы сдвигаются вправо
	///
	/// добавляемый список
	/// true, если получилось добавить, false - если не получилось
	bool addAll(int index, ArrayList& list);

	/// /// удалить все элементы из списка
	///
	void clear();

	/// /// содержится ли элемент в списке
	///
	/// искомый элемент
	/// true - содержится, false - не содержится
	bool contains(int element);

	/// /// получить элемент по индексу
	///
	/// индекс запрашиваемого элемента
	/// data[index], если индекс корректен, -1 - если индекс некорректен
	int get(int index);

	/// /// поиск элемента в списке
	///
	/// искомый элемент
	/// индекс элемента, если он найден, -1 - если не найден
	int indexOf(int element);

	/// /// проверка списка на пустоту
	///
	/// true - если список пуст, false - если есть хотя бы 1 элемент
	bool isEmpty();

	/// /// Вывод списка в формате [count/capacity] {el1, el2, el3, ...}
	///
	void print();

	/// /// удаление элемента из списка
	///
	/// индекс удаляемого элемента
	/// true - все прошло хорошо, false - возникли проблемы
	bool remove(int index);

	/// /// поменять местами элементы
	///
	/// индекс первого элемента
	/// индекс второго элемента
	/// true - все прошло хорошо, false - возникли проблемы
	int swap(int index1, int index2);

};