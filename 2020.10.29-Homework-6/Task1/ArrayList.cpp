#include "ArrayList.h"

ArrayList::ArrayList()
{
	count = 0;
	capacity = 10;
	data = new int[capacity];
	str = nullptr;
}

ArrayList::ArrayList(const ArrayList& list)
{
	count = list.count;
	capacity = list.capacity;
	data = list.data;
	str = nullptr;
}

ArrayList::~ArrayList()
{
	delete[] data;
	if (str != nullptr)
	{
		delete[] str;
	}
}

void ArrayList::expand()
{
	int* newData = new int[capacity + 10];
	for (int i = 0; i < capacity; ++i)
	{
		newData[i] = data[i];
	}
	capacity += 10;
	delete[] data;
	data = newData;
}

int ArrayList::numLength(int number)
{
	int result = 1;
	if (number < 0)
	{
		number = -number;
	}
	while (number > 9)
	{
		number /= 10;
		result++;
	}
	return result;
}

void ArrayList::addToStr(int& index, char symbol)
{
	str[index] = symbol;
	++index;
}

void ArrayList::addToStr(int& index, int number)
{
	int length = numLength(number);
	bool t = false;
	if (number < 0)
	{
		length++;
		number = -number;
		t = true;
	}
	for (int i = 0; i < length; ++i)
	{
		int digit = number % 10;
		str[index + length - 1 - i] = '0' + digit;
		number /= 10;
	}
	if (t == true)
	{
		str[index] = '-';
	}
	index += length;
}

bool ArrayList::add(int element)
{
	if (count == capacity)
	{
		expand();
	}
	data[count++] = element;
	return true;
}

bool ArrayList::add(int index, int element)
{
	if (index < 0 || index > count)
	{
		return false;
	}
	for (int i = count; i > index; --i)
	{
		data[i] = data[i - 1];
	}
	data[index] = element;
	count++;
	return true;
}

bool ArrayList::addAll(ArrayList& list)
{
	if (list.count == 0)
	{
		return false;
	}
	for (int i = 0; i < list.count; ++i)
	{
		if (count == capacity)
		{
			expand();
		}
		data[count] = list.data[i];
		count++;
	}
	return true;
}

bool ArrayList::addAll(int index, ArrayList& list)
{
	if (list.count == 0)
	{
		return false;
	}
	if (index < 0 || index > count)
	{
		return false;
	}
	while (capacity <= count + list.count)
	{
		expand();
	}
	for (int i = count - 1; i >= index; --i)
	{
		data[i + list.count] = data[i];
	}
	for (int i = 0; i < list.count; ++i)
	{
		data[index + i] = list.data[i];
	}
	count += list.count;
	return true;
}

void ArrayList::clear()
{
	count = 0;
}

bool ArrayList::contains(int element)
{
	for (int i = 0; i < count; ++i)
	{
		if (data[i] == element)
		{
			return true;
		}
	}
	return false;
}

int ArrayList::get(int index)
{
	if (index < 0 || index >= count)
	{
		return -1;
	}
	return data[index];
}

bool ArrayList::set(int index, int element)
{
	if (index < 0 || index > count - 1)
	{
		return false;
	}
	data[index] = element;
	return false;
}

int ArrayList::indexOf(int element)
{
	for (int i = 0; i < count; ++i)
	{
		if (data[i] == element)
		{
			return i;
		}
	}
	return -1;
}

bool ArrayList::isEmpty()
{
	return count == 0;
}

char* ArrayList::toString()
{
	if (str != nullptr)
	{
		delete[] str;
		str = nullptr;
	}
	int len = length() + length() + length() + length() + length() + 9;
	str = new char[len];
	int index = 0;
	addToStr(index, '[');
	addToStr(index, count);
	addToStr(index, '/');
	addToStr(index, capacity);
	addToStr(index, ']');
	addToStr(index, ' ');
	addToStr(index, '{');
	for (int i = 0; i < length(); ++i)
	{
		addToStr(index, data[i]);
		if (length() - 1 != i)
		{
			addToStr(index, ',');
			addToStr(index, ' ');
		}
	}
	addToStr(index, '}');
	addToStr(index, '\0');
	return str;
}

bool ArrayList::remove(int index)
{
	if (count == 0)
	{
		return false;
	}
	if (index < 0 || index >= count)
	{
		return false;
	}
	for (int i = index + 1; i < count; ++i)
	{
		data[i - 1] = data[i];
	}
	data[count - 1] = 0;
	count--;
	return true;
}

bool ArrayList::swap(int index1, int index2)
{
	if (index1 < 0 || index1 >= count || index2 < 0 || index2 >= count)
	{
		return false;
	}
	int x = get(index1);
	int y = get(index2);
	set(index1, y);
	set(index2, x);
	return true;
}

int ArrayList::length()
{
	return count;
}
