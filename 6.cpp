// Посчитать факториал числа
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int faktorial = 1;
	for (int i = 2; i <= n; ++i)
	{
		faktorial *= i;
	}
	cout << faktorial;
	return 0;
}