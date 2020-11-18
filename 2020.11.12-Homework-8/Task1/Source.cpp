/*продемонстрировать работу всех функций
показать, что все функции и операторы корректно работают:
1). С пустым списком.
2). Со списком из 1 элемента.
3). Со списком из нескольких элементов.
*/

#include<iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList list;
	cout << list << endl;
	list.addToHead(5);
	cout << "addToHead(5)	" << list << endl;
	list.addToHead(6);
	cout << "addToHead(6)	" << list << endl;
	list.addToTail(8);
	cout << "addToTail(8)	" << list << endl;
	list.addToTail(4);
	cout << "addToTail(4)	" << list << endl;
	list.add(2, 9);
	cout << "add(2, 9)	" << list << endl;
	list.add(3, 12);
	cout << "add(2, 9)	" << list << endl;
	list.add(1, 7);
	cout << "add(2, 9)	" << list << endl;


	cout << "get(5)	" << list.get(5) << endl;
	cout << "get(2)	" << list.get(2) << endl;
	list.set(3, 4);
	cout << "set(3, 4)	" << list << endl;
	list.set(4, 65);
	cout << "set(4, 65)	" << list << endl;

	cout << "list[2] = " << list[2] << endl;
	list[1] = 12354;
	cout << "list[1] = " << list[1] << endl;
	list[-12] = -12;
	cout << "list[-12] = -12	" << list << endl;
	/*list[-5] = 48;
	cout << "list[-5] = 48	" << list << endl;*/
	list[5123] = 1;
	cout <<"list[5123] = 1	"<< list << endl;

	list.extractHead();
	cout << "list.extractHead()	" << list << endl;
	list.extractTail();
	cout << "list.extractTail()	" << list << endl;
	list.extract(2);
	cout << "list.extract(2)	" << list << endl;
	list += 122;
	cout << "list += 122	" << list << endl;
	list -= 2;
	cout << "list -= 2	" << list << endl;
	list -= 1000;
	cout << "list -= 1000	" << list << endl;
	//LinkedList listCopy = list;
	return 0;
}