// Написать программу, печатающую все простые числа, не превосходящие заданного
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i)
	{
		int k = 0;
		for (int j = 2; j <= sqrt(i); ++j)
		{
			if (i % j == 0)
			{
				++k;
				break;
			}
		}
		if (k == 0)
		{
			cout << i<<", ";
		}
	}
	return 0;
}
