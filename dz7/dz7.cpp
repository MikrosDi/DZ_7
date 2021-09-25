﻿
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <fstream>
#include <locale>
#include <string>
#include <filesystem>
#include "mylib.h"
#include <stdio.h>

using namespace std;

#define MY_DIAPAZON(cin_number, diapazon) ((cin_number >= 0 && cin_number < diapazon))

#define PUZIREK(a, b)

#pragma pack(push, 1)
struct ANKETA 
{
	char SotFullName[100];   
	char SotAge[150];        
	short SotRang;           
	short SotSalary;           
	char SotPhoneNymber;           
};
#pragma pack(pop)


int main()
{
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*Task 1 and 5.
	Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h)
	во втором модуле mylib объявить 3 функции:
	для инициализации массива (типа float), печати его на экран и подсчета количества отрицательных и положительных элементов.
	Вызывайте эти 3-и функции из main для работы с массивом.*/
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	setlocale(LC_ALL, "rus");
	cout << "Задание первое:" << endl;
	float* ptr = MyLib::Create(6);
	MyLib::Plus_and_minus(ptr, 6);
	MyLib::Print(ptr, 6);
	cout <<"\n\n";
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*Task 2.
	Описать макрокоманду (через директиву define),
	проверяющую, входит ли переданное ей число (введенное с клавиатуры) в диапазон от нуля (включительно)
	до переданного ей второго аргумента (исключительно) и возвращает true или false, вывести на экран «true» или «false».*/
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	cout << "Задание второе:" << endl;
	int number;
	const int MAX_DIAPAZON = 10;
	cout << "Введите число: " << endl;
	cin >> number;
	bool rezult = MY_DIAPAZON(number, MAX_DIAPAZON);
	cout << "Ваше число " << (rezult ? "= true и оно входит в диапазон." : "= false и оно не входит в диапазон.") << "\n\n";

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*Task 3.
	Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define.
	Инициализируйте его через ввод с клавиатуры. Напишите для него свою функцию сортировки (например Пузырьком).
	Реализуйте перестановку элементов как макрокоманду SwapINT(a, b). Вызывайте ее из цикла сортировки.*/
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	cout << "Задание третье:" << endl;
	PUZIREK(a, b)
	int* b;
	int a;
	cout << "Введите ваше число: ";
	cin >> a;
	b = new int[a];

	for (int i = 0; i < a; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> b[i];
	}
	int time_perem; 
	
	for (int i = 0; i < a - 1; i++)
	{
		for (int j = 0; j < a - i - 1; j++)
		{
			if (b[j] > b[j + 1])
			{
				
				time_perem = b[j];
				b[j] = b[j + 1];
				b[j + 1] = time_perem;
			}
		}
	}	
	   for (int i = 0; i < a; i++) 
	   {
		cout << b[i] << " ";
	   }
	   cout << endl;
	   
	delete[] b; 

	cout << "\n";
	   
   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   /*Task 4*.
   Объявить структуру Сотрудник с различными полями. 
   Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack. 
   Выделите динамически переменную этого типа. Инициализируйте ее.
   Выведите ее на экран и ее размер с помощью sizeof. 
   Сохраните эту структуру в текстовый файл.*/
   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	auto* Personal = new ANKETA;	
	cout << "Размер = " << sizeof(ANKETA) << " байт" << endl;
	cout << "Текстовый файл создан! " << "\n";
	string path = "dzSeven.txt";
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		string ANKETA;		
		fout << &Personal;
	}
	fout.close();

	delete Personal;
       
	return 0;
};