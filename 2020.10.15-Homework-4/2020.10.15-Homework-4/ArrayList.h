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

	//������
	/// <summary>
	/// ��������� ������� � �����
	///</summary>
	/// <param name="element">����������� �������</param>
	/// <returns></returns>
	bool add(int element);
	/// <summary>
	/// ��������� ������� � ������� index, ��� ����������� �������� ���������� �� 1 ������
	/// </summary>
	/// <param name="index">������ ������������ ��������</param>
	/// <param name="element">����������� �������</param>
	/// <returns>true, ���� ��� ������ ������, false - ���� �������� ��������</returns>
	bool add(int index, int element);


	/// /// ��������� ��� �������� �� ������ list � �����
	///
	/// ����������� ������
	/// true, ���� ���������� ��������, false - ���� �� ����������
	bool addAll(ArrayList& list);

	/// /// ��������� ��� �������� �� ������ list, ������� � ������� index.
	/// ��� ����������� �������� ���������� ������
	///
	/// ����������� ������
	/// true, ���� ���������� ��������, false - ���� �� ����������
	bool addAll(int index, ArrayList& list);

	/// /// ������� ��� �������� �� ������
	///
	void clear();

	/// /// ���������� �� ������� � ������
	///
	/// ������� �������
	/// true - ����������, false - �� ����������
	bool contains(int element);

	/// /// �������� ������� �� �������
	///
	/// ������ �������������� ��������
	/// data[index], ���� ������ ���������, -1 - ���� ������ �����������
	int get(int index);

	/// /// ����� �������� � ������
	///
	/// ������� �������
	/// ������ ��������, ���� �� ������, -1 - ���� �� ������
	int indexOf(int element);

	/// /// �������� ������ �� �������
	///
	/// true - ���� ������ ����, false - ���� ���� ���� �� 1 �������
	bool isEmpty();

	/// /// ����� ������ � ������� [count/capacity] {el1, el2, el3, ...}
	///
	void print();

	/// /// �������� �������� �� ������
	///
	/// ������ ���������� ��������
	/// true - ��� ������ ������, false - �������� ��������
	bool remove(int index);

	/// /// �������� ������� ��������
	///
	/// ������ ������� ��������
	/// ������ ������� ��������
	/// true - ��� ������ ������, false - �������� ��������
	int swap(int index1, int index2);

};