// 5. ѕосчитать количество делителей числа.
#include <iostream>
using namespace std;
int main()
{
	int n = 0, k = 1;
	cin >> n;
	while (n > 1)
	{
		for (int i = 2; true; ++i)
		{
			if (n % i == 0)
			{
				n /= i;
				k++;
				break;
			}
		}
	}
	cout << k;
	return 0;
}