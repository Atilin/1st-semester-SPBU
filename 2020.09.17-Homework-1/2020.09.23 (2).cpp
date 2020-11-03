// Написать программу нахождения неполного частного от деления a на b (целые числа), используя только операции сложения, вычитания и умножения
#include <iostream>
using namespace std;
int main()
{
	int a = 0, b = 0;
	cin >> a >> b;
	int count = 0;
	while (true)
	{
		if (a - b >= 0)
		{
			count++;
			a -= b;
		}
		else
			break;
	}
	cout << count;
	return 0;
}