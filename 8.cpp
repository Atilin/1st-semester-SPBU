// Посчитать 2^n с помощью побитовых сдвигов
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int k = 1 << n;
	cout << k;
	return 0;
}