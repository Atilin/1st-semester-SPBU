#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	cout << "How many array elements do you want to enter?\n\n";
	double n;
	cin >> n;
	cout << endl;
	cout << "enter " << n << " array elements\n\n";
	vector <double> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cout << endl;
	sort(a.begin(), a.end());
	double faktorial = 1;
	double sum = 0;
	int j = 0;
	for (int i = 1; i <= a[n - 1]; ++i)
	{
		faktorial *= i;
		while (j < n && i == a[j])
		{
			sum += faktorial;
			++j;
		}
	}
	cout << "the arithmetic mean of the factorials is equal to  " << sum / n << endl << endl;
	return 0;
}