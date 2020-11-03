// Написать программу, считающую значение формулы x^4 + x^3 + x^2 + x + 1 за два умножения
#include<iostream>
using namespace std;
int main()
{
	int x = 0;
	cin >> x;
	int a = x * x;
	cout << (a + 1) * (a + x) + 1;
	return 0;
}
