// Ќаписать программу, считающую значение формулы x^4 + x^3 + x^2 + x + 1 за два умножени€
#include <iostream>
using namespace std;
int main()
{
	int x;
	cin >> x;
	cout << pow(x, 4) + x*x*x + pow(x, 2) + x + 1; //фактически здесь два умножени€ (два знака умножить)
	return 0;
}