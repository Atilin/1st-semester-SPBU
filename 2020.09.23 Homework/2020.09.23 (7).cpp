#include <iostream>
using namespace std;
int main()
{
	int n = 0, k = 0;
	cin >> n >> k;
	int stepenN = 1;
	for (int i = 0; i < k; ++i)
	{
		stepenN *= n;
	}
	cout << stepenN;
	return 0;
}