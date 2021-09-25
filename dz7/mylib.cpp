#include <iostream>
#include <cstdlib>
using namespace std;

namespace MyLib
{
	//Task 1
	float* Create(const int n)
	{
		float* ptr = new float[n];
		setlocale(LC_ALL, "rus");
		for (int i = 0; i < n; i++) {
			ptr[i] = (i % 2 == 1 ? 1 : -1) * i;
		}
		return ptr;
	}

	void Plus_and_minus(float* ptr, const int n)

	{
		setlocale(LC_ALL, "rus");
		int a = 0, b = 0;
		for (int i = 0; i < n; i++)
		{
			if (ptr[i] < 0)
				a++;
			else
				b++;
		}
		cout << "Положительных = " << b << endl;
		cout << "Отрицательных = " << a << endl;
	}

	void Print(float* ptr, const int n)
	{
		setlocale(LC_ALL, "rus");
		for (int o = 0; o < n; o++)
			cout << ptr[o] << " ";
	}
}