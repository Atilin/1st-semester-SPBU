// 5. ѕосчитать количество делителей числа.
#include <iostream>
using namespace std;
int main()
{
	int n = 0, k = 0;
	cin >> n;
	for (int i = 1; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
		{
			k++;
		}
	}
	k *= 2;
	int zatichka = sqrt(n);
	if (zatichka * zatichka == n)
	{
		--k;
	}
	cout << k;
	return 0;
}
