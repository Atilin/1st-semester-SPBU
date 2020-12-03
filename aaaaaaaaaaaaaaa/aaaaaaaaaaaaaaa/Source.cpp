#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double myPow(double k, int n) // для неотрицательной степени
{
	double ans = k;

	if (n == 0)
		return 1;

	for (int i = 1; i < n; ++i)
	{
		ans *= k;
	}
	return ans;
}

double myFunction(double x, int n)
{
	int m = 0;
	int aa1 = -1;
	int aa2 = -2;
	double ans = 0;

	while (aa1 != aa2)
	{
		double sum1 = 0;
		double sum2 = 0;
		for (int i = 0; i <= m + 1; ++i)
		{
			sum2 = sum2 + myPow(-1, i) * myPow(x, 2 * i + 1) / (2 * i + 1);
			if (i == m)
			{
				sum1 = sum2;
				ans = sum1;
			}
		}
		aa1 = sum1 * myPow(10, n);
		aa2 = sum2 * myPow(10, n);

		m++;
	}
	return ans;
}

int main()
{
	double x = 0;
	int n = 0;

	cin >> x >> n;

	if (x >= 1 || x <= -1)
	{
		cout << "wrong input\n";
		return 0;
	}
	if (n < 0)
	{
		cout << "wrong input\n";
		return 0;
	}

	cout << setprecision(9) << atan(x) << endl;
	cout << setprecision(9) << myFunction(x, n) << endl;
	return 0;
}