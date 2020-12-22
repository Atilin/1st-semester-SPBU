#include <iostream>

using namespace std;

int** initMatrix(int dimention)
{
	int** matrix = new int* [dimention] { 0 };
	for (int i = 0; i < dimention; ++i)
	{
		matrix[i] = new int[dimention] { 0 };
	}
	return matrix;
}

void freeMatrix(int** matrix, int dimention)
{
	for (int i = 0; i < dimention; ++i)
	{
		for (int j = 0; j < dimention; ++j)
		{
			matrix[i][j] = 0;
		}
	}
}

void printMatrix(int** matrix, int dimention)
{
	for (int i = 0; i < dimention; ++i)
	{
		for (int j = 0; j < dimention; ++j)
		{
			printf("%3d ", matrix[i][j]);
		}
		cout << endl;
	}
}

void deleteMatrix(int** matrix, int dimention)
{
	for (int i = 0; i < dimention; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int main()
{
	int n = 0;
	cin >> n;
	int** a = initMatrix(n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			a[i][j] = i + j + 1;
		}
	}
	printMatrix(a, n);
	cout << endl;
	freeMatrix(a, n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			a[i][j] = 2 * n - i - j - 1;
		}
	}
	printMatrix(a, n);
	cout << endl;
	freeMatrix(a, n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			a[i][j] = j + 1;
		}
	}
	printMatrix(a, n);
	cout << endl;
	freeMatrix(a, n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j <= i)
			{
				a[i][j] = j + 1;
			}
			else
			{
				a[i][j] = i + 1;
			}
		}
	}
	printMatrix(a, n);
	cout << endl;
	freeMatrix(a, n);


	int up = 0;
	int down = n - 1;
	int left = 0;
	int right = n - 1;
	int i = 0, j = 0;
	int element = 1;
	while (left < right || up < down)
	{
		while (j <= right)
		{
			a[i][j] = element;
			element++;
			j++;
		}
		up++;
		j--;
		i++;
		while (i <= down)
		{
			a[i][j] = element;
			element++;
			i++;
		}
		right--;
		i--;
		j--;
		while (j >= left)
		{
			a[i][j] = element;
			element++;
			j--;
		}
		down--;
		j++;
		i--;
		while (i >= up)
		{
			a[i][j] = element;
			element++;
			i--;
		}
		left++;
		i++;
		j++;
	}
	if (n % 2 != 0)
	{
		a[i][j] = element;
	}
	printMatrix(a, n);
	cout << endl;
	freeMatrix(a, n);


	deleteMatrix(a, n);
	return 0;
}