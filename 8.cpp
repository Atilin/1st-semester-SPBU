// ��������� 2^n � ������� ��������� �������
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int k = 1 << n;
	cout << k;
	return 0;
}