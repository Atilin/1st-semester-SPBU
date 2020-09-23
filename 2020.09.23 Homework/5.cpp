// 5. Посчитать количество делителей числа.
#include <iostream>
using namespace std;
int main()
{
	int n = 0, k=0;
	cin >> n;
	for (int i = 1; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
		{
			k++;
		}
	}
	k *= 2;
	if (sqrt(n) * sqrt(n) == n)
	{
		--k;
	}
	cout << k;
	return 0;
}
