#include "ArrayList.h"

ArrayList::ArrayList()
{
	count = 0;
	capacity = 10;
	data = new int[capacity];
}

ArrayList::ArrayList(const ArrayList& list)
{
	count = list.count;
	capacity = list.capacity;
	data = new int[capacity];
	for (int i = 0; i < count; data[i] = list.data[i], ++i);
}

ArrayList::~ArrayList()
{
	delete[] data;
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
	if (count == capacity)
	{
		expand();
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
	for (int i = count - 1; i >= 0; --i)
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

void ArrayList::operator+=(int item)
{
	add(item);
}

void ArrayList::operator-=(int item)
{
	remove(indexOf(item));
}

ArrayList& ArrayList::operator=(const ArrayList& list)
{
	// TODO: вставьте здесь оператор return
	if (&list != this)
	{
		count = list.count;
		capacity = list.capacity;
		delete[] data;
		data = new int[capacity];
		for (int i = 0; i < list.count; ++i)
		{
			data[i] = list.data[i];
		}
	}
	return *this;
}

ArrayList operator+(const ArrayList& list, int item)
{
	ArrayList temp(list);
	temp += item;
	return temp;
}

ArrayList operator+(int item, const ArrayList& list)
{
	ArrayList temp(list);
	temp.add(0, item);
	return temp;
}

ArrayList operator+(const ArrayList& list1, const ArrayList& list2)
{
	ArrayList temp(list2);
	for (int i = 0; i < list1.count; ++i)
	{
		temp += list1.data[i];
	}
	return temp;
}

ArrayList operator-(const ArrayList& list, int item)
{
	ArrayList temp(list);
	temp -= item;
	return temp;
}

ArrayList operator-(int item, const ArrayList& list)
{
	ArrayList temp(list);
	for (int i = 0; i < list.count; ++i)
	{
		if (item == temp.data[i])
		{
			temp.remove(i);
			return temp;
		}
	}
	return temp;
}

std::ostream& operator<<(std::ostream& stream, const ArrayList& list)
{
	// TODO: вставьте здесь оператор return
	stream << "{ ";
	for (int i = 0; i < list.count; ++i)
	{
		stream << list.data[i] << " ";
	}
	stream << '}';
	return stream;
}
