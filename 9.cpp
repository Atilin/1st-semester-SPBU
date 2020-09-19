// Посчитать 2^n - 1 с помощью побитовых сдвигов и инверсии

#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	n = 1 << n;
	n *= -1;
	n = ~n;
	cout << n;
	return 0;
}
