// ��������� 2^n - 1 � ������� ��������� ������� � ��������

#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	n = ~n;
	n = ~n;
	n = 1 << n;
	n--;
	cout << n;
	return 0;
}