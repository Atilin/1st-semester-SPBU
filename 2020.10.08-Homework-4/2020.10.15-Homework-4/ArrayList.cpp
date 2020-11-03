#include "ArrayList.h"

using namespace std;

ArrayList::ArrayList()
{
	//printf("Default constructor call\n");
	capacity = 10;
	count = 0;
	data = new int[10];
}

ArrayList::ArrayList(int capacity)
{
	//printf("Parametrized constructor call\n");
	capacity = capacity;
	count = 0;
	data = new int[capacity];
}

ArrayList::~ArrayList()
{
	//printf("Destructor call %d\n", capacity);
	delete[] data;
}

void expand(int*& data, int& capacity)
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

bool ArrayList::isEmpty()
{
	return count == 0;
}

void ArrayList::print()
{
	printf("[%d/%d] {", count, capacity);
	if (count == 0)
	{
		printf("EMPTY");
	}
	else
	{
		for (int i = 0; i < count; ++i)
		{
			printf("%d%s", data[i], (i == count - 1 ? "" : ", "));
		}
	}
	printf("}\n");
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

int ArrayList::swap(int index1, int index2)
{
	if (index1 < 0 || index1 >= count || index2 < 0 || index2 >= count)
	{
		return false;
	}
	int x = 0;
	x = data[index1];
	data[index1] = data[index2];
	data[index2] = x;
	return true;
}

bool ArrayList::add(int element)
{
	if (capacity == count)
	{
		expand(data, capacity);
	}
	data[count] = element;
	count++;
	return 0;
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
			expand(data, capacity);
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
		expand(data, capacity);
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
