// Вывести на экран все счастливые билеты с заданной суммой чисел
#include <iostream>
#include <clocale>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	int l = 0, r = 0;
	int k = 0;
	while (l < 1000)
	{
		int a1 = l / 100, a2 = l / 10 % 10, a3 = l % 10;
		if (a1 + a2 + a3 == n)
		{
			while (r < 1000)
			{
				int b1 = r / 100, b2 = r / 10 % 10, b3 = r % 10;
				if (b1 + b2 + b3 == n)
				{
					cout << a1 << a2 << a3 << b1 << b2 << b3 << endl;
					k++;
				}
				r++;
			}
			r = 0;
		}
		l++;
	}
	cout << k << " tickets";
	return 0;
}
