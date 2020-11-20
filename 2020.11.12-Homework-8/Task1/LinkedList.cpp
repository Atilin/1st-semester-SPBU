#include "LinkedList.h"

LinkedList::LinkedList(const LinkedList& list)
{
	tail = head = nullptr;
	count = 0;

	Node* temp = list.head;
	while (temp != nullptr)
	{
		addToTail(temp->data);
		temp = temp->next;
	}
}

LinkedList::~LinkedList()
{
	while (!isEmpty())
	{
		extractHead();
	}
}

bool LinkedList::isEmpty()
{
	return (head == nullptr);
}

bool LinkedList::indexValid(int index)
{
	return (index >= 0 && index < count);
}

int LinkedList::length()
{
	return count;
}

bool LinkedList::addToHead(int element)
{
	if (head == nullptr)
	{
		head = tail = new Node(element);
	}
	else
	{
		head = new Node(element, head);
	}
	++count;
	return true;
}

bool LinkedList::addToTail(int element)
{
	if (tail == nullptr)
	{
		head = tail = new Node(element);
	}
	else
	{
		/*
		Node* newTail = new Node(element);
		(*tail).next = newTail;
		tail = (*tail).next;
		*/
		tail->next = new Node(element);
		tail = tail->next;
	}
	++count;
	return true;
}

bool LinkedList::add(int index, int element)
{
	if (index == 0)
	{
		return addToHead(element);
	}
	if (index == count)
	{
		return addToTail(element);
	}
	if (!indexValid(index))
	{
		return false;
	}

	Node* temp = head;
	for (int i = 0; i < index - 1; ++i)
	{
		temp = temp->next;
	}
	temp->next = new Node(element, temp->next);
	++count;

	return true;
}

int LinkedList::get(int index)
{
	if (!indexValid(index))
	{
		return -1;
	}
	if (index == 0)
	{
		return head->data;
	}
	if (index == count - 1)
	{
		return tail->data;
	}

	Node* temp = head;
	for (int i = 0; i < index; ++i)
	{
		temp = temp->next;
	}
	return temp->data;

}

bool LinkedList::set(int index, int element)
{
	if (!indexValid(index))
	{
		return false;
	}
	if (index == 0)
	{
		head->data = element;
	}
	else if (index == count - 1)
	{
		tail->data = element;
	}
	else
	{
		Node* temp = head;
		for (int i = 0; i < index; ++i)
		{
			temp = temp->next;
		}
		temp->data = element;
	}
	return true;
}

int& LinkedList::operator[](int index)
{
	if (head == nullptr)
	{
		addToHead(0);
		return head->data;
	}
	if (index <= 0)
	{
		return head->data;
	}
	if (index >= count)
	{
		addToTail(0);
		return tail->data;
	}
	if (index == count - 1)
	{
		return tail->data;
	}
	Node* temp = head;
	for (int i = 0; i < index; ++i)
	{
		temp = temp->next;
	}
	return temp->data;
}

int LinkedList::extractHead()
{
	if (head == nullptr)
	{
		return -1;
	}
	if (head == tail)
	{
		int oldHead = head->data;
		delete head;
		tail = head = nullptr;
		count = 0;
		return oldHead;
	}
	int oldHead = head->data;
	Node* node = head;
	head = head->next;
	delete node;
	--count;
	return oldHead;
}

int LinkedList::extractTail()
{
	if (tail == nullptr)
	{
		addToTail(0);
		return tail->data;
	}
	if (head->next == nullptr)
	{
		delete head;
		head == nullptr;
	}
	Node* node = head;
	while (node->next != nullptr && node->next->next != nullptr)
	{
		node = node->next;
	}
	int oldTail = node->data;
	delete node->next;
	node->next = nullptr;
	return oldTail;
}

int LinkedList::extract(int index)
{
	if (head == nullptr)
	{
		return -1;
	}
	if (!indexValid(index))
	{
		return -1;
	}
	Node* node = head;
	for (int i = 0; i < index - 1; ++i)
	{
		node = node->next;
	}
	Node* temp = node->next;
	int oldElement = node->data;
	node->next = node->next->next;
	delete temp;
	return oldElement;
}

void LinkedList::operator+=(int element)
{
	addToTail(element);
}

void LinkedList::operator-=(int index)
{
	extract(index);
}

LinkedList& LinkedList::operator=(const LinkedList list)
{
	if (&list != this)
	{
		count = list.count;
		head = list.head;
		tail = list.tail;
	}
	return *this;
}

int LinkedList::indexOf(int element)
{
	Node* temp = head;
	for (int index = 0; temp != nullptr; ++index)
	{
		if (temp->data == element)
		{
			return index;
		}
		temp = temp->next;
	}
	return -1;
}

bool LinkedList::contains(int element)
{
	return (indexOf(element) < 0 ? false : true);
}

std::ostream& operator<<(std::ostream& stream, const LinkedList list)
{
	stream << "[" << list.count << "]{";
	if (list.head == nullptr)
	{
		stream << "EMPTY";
	}
	else
	{
		Node* temp = list.head;
		while (temp != nullptr)
		{
			stream << temp->data;
			if (temp->next != nullptr)
			{
				stream << ", ";
			}
			temp = temp->next;
		}
	}
	stream << "}";

	return stream;
}