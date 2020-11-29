#include <iostream>
#include <string>
#include "Functions.h"

using namespace std;

void resolveError(int errorCode)
{
	string out1[15] = { "нажали на пробел", "ввели символ", "ввели английскую букву", "ввели две точки" };

	int which = rand() % 2 + 1;
	if (which == 1)
	{
		cout << "О, великая родственница, извините за ограниченный функционал программы, должно быть, вы случайно " << out1[errorCode - 1] << ". Пожалуйста, попробуйте еще раз" << endl;
	}
	else
	{
		cout << "Великолепная и неповторимая родственница, прошу прощения за ограниченный функционал программы, вероятно, вы, сами того не заметив, " << out1[errorCode - 1] << ". Пожалуйста, повторите ввод еще раз" << endl;
	}
}

int readLong(long long& ll)
{
	string s;
	long long temp = 0;
	getline(cin, s);
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == 32)//пробел
		{
			resolveError(1);
			return 0;
		}
		if (s[i] >= 33 && s[i] <= 47)//символы
		{
			resolveError(2);
			return 0;
		}
		if (s[i] >= 58 && s[i] <= 64)//символы
		{
			resolveError(2);
			return 0;
		}
		if (s[i] >= 91 && s[i] <= 96)//символы
		{
			resolveError(2);
			return 0;
		}
		if (s[i] >= 123 && s[i] <= 127)//символы
		{
			resolveError(2);
			return 0;
		}
		if (s[i] >= 65 && s[i] <= 90)//англ буквы
		{
			resolveError(3);
			return 0;
		}
		if (s[i] >= 97 && s[i] <= 122)//англ буквы
		{
			resolveError(3);
			return 0;
		}
		//if (s[i] >= 128 && s[i] <= 175)//русские буквы
		//{
		//	resolveError(4);
		//	return 0;
		//}
		//if (s[i] >= 224 && s[i] <= 241)//русские буквы
		//{
		//	resolveError(4);
		//	return 0;
		//}
		if (s[i] >= 48 && s[i] <= 57)
		{
			temp = temp * 10 + (s[i] - '0');
		}
		else
		{
			cout << "Вы допустили невиданную в мире ошибку, разбирайтесь сами" << endl;
			return 0;
		}
	}
	ll = temp;
	return ll;
}

double readDouble(double& d)
{
	string h;
	double temp = 0;
	getline(cin, h);
	bool point = false;
	int count = 0;
	for (int i = 0; i < h.size(); ++i)
	{
		if (h[i] == 32)//пробел
		{
			resolveError(1);
			return 0;
		}
		if (h[i] >= 33 && h[i] <= 45)//символы
		{
			resolveError(2);
			return 0;
		}
		if (h[i] == 47)//символы
		{
			resolveError(2);
			return 0;
		}
		if (h[i] >= 58 && h[i] <= 64)//символы
		{
			resolveError(2);
			return 0;
		}
		if (h[i] >= 91 && h[i] <= 96)//символы
		{
			resolveError(2);
			return 0;
		}
		if (h[i] >= 123 && h[i] <= 127)//символы
		{
			resolveError(2);
			return 0;
		}
		if (h[i] >= 65 && h[i] <= 90)//англ буквы
		{
			resolveError(3);
			return 0;
		}
		if (h[i] >= 97 && h[i] <= 122)//англ буквы
		{
			resolveError(3);
			return 0;
		}
		//if (h[i] >= 128 && h[i] <= 175)//русские буквы
		//{
		//	resolveError(4);
		//	return 0;
		//}
		//if (h[i] >= 224 && h[i] <= 241)//русские буквы
		//{
		//	resolveError(4);
		//	return 0;
		//}
		if (point == true && h[i] == '.')
		{
			resolveError(4);
			return 0;
		}
		if (point == true)
		{
			count++;
		}
		if (h[i] == '.')
		{
			point = true;
		}
		if (h[i] >= 48 && h[i] <= 57)
		{
			temp = temp * 10 + (h[i] - '0');
		}
		else
		{
			cout << "Вы допустили невиданную в мире ошибку, разбирайтесь сами" << endl;
			return 0;
		}

	}
	d = temp;
	d /= pow(10, count);
	return d;
}
