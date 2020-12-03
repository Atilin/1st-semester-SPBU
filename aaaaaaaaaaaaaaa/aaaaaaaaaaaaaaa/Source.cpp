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

double teylor(double x, int k)
{
	double sum = 0;
	for (int i = 0; i <= k; ++i)
	{
		sum = sum + myPow(-1, i) * myPow(x, 2 * i + 1) / (2 * i + 1);
	}
	return sum;
}

double myFunction(double x, int n)
{
	int m = 0;
	double nznak1 = teylor(x, m) * myPow(10, n);
	double nznak2 = teylor(x, m+1) * myPow(10, n);

	//cout << "teylor " << teylor(x, m) << endl;

	//cout << "myPow " << myPow(10, n) << endl;

	//cout << "nznak " << nznak1 << ' ' << nznak2 << endl;

	int aa1 = nznak1;
	int aa2 = nznak2;
	//cout <<"aa "<< aa1 << ' ' << aa2 << endl;
	while (aa1 != aa2)
	{
		//teylor(x, m);
		//teylor(x, m + 1);

		nznak1 = teylor(x, m) * myPow(10, n);
		nznak2 = teylor(x, m+1) * myPow(10, n);

		aa1 = nznak1;
		aa2 = nznak2;

		//cout << "aa1" << ' ' << aa1 << endl;

		//cout << "aa2" << ' ' << aa2 << endl;

		m++;
	}
	return teylor(x, m - 1);
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
	//cout << myPow(-2, 2);

	//cout <<"teylor "<< teylor(x, n) << endl;

	cout << setprecision(9) << atan(x) << endl;
	cout << setprecision(9) << myFunction(x, n) << endl;
	return 0;
}