#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;


void CreateBIN(char* fname) // створення файлу символів з введених рядків
{
	ofstream fout(fname, ios::binary); // відкрили файл для запису
	char ch; // відповідь користувача – чи продовжувати введення
	string s; // введений користувачем рядок

		cin.get(); // очищуємо буфер клавіатури – щоб не було символу
		cin.sync(); // "кінець рядка", який залишився після вводу числа
		cout << "enter line: "; getline(cin, s); // ввели рядок
		for (unsigned i = 0; i < s.length(); i++) // скануємо введений рядок
			fout.write((char*)&s[i], sizeof(s[i])); // записали символ у файл

	cout << endl;
}
void PrintBIN(char* fname) // виведення файлу на екран
{
	ifstream fin(fname, ios::binary); // відкрили файл для зчитування
	char c; // прочитаний символ
	while (fin.read((char*)&c, sizeof(c))) // поки можна прочитати символ
	{
		cout << c << endl; // виводимо його на екран
	}
	cout << endl;
}
bool ContainsInArr(char* char_arr, char oneSymbol, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (oneSymbol == char_arr[i])
			return true;
	}
	return false;
}
void ProcessBIN1(char* fname, char* gname) 
{ 
	string geometry = "геометрія";
	int n = geometry.length();
	char* char_array = new char[n + 1];

	strcpy(char_array, geometry.c_str());

	ifstream f(fname, ios::binary); // відкрили файл для зчитування
	ofstream g(gname, ios::binary); // відкрили файл для запису
	char c; // прочитаний символ
	while (f.read((char*)&c, sizeof(c))) // поки можна прочитати символ
	{
		if (!ContainsInArr(char_array, c, n)) {
			g.write((char*)&c, sizeof(c));
		}
	}
}

void fWrite(fstream& f, const int i, const char x)
{
	f.seekp(i * (long)sizeof(char)); // встановили вказівник
	f.write((char*)&x, sizeof(char)); // записали значення
}
char fRead(fstream & f, const int i)
{
	char x;
	f.seekg(i * (long)sizeof(char)); // встановили вказівник
	f.read((char*)&x, sizeof(char)); // прочитали значення
	return x;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char fname[100]; 
	cout << "enter file name 1: "; cin >> fname;
	CreateBIN(fname);
	PrintBIN(fname); 
	char gname[100];
	cout << "enter file name 2: "; cin >> gname;

	ProcessBIN1(fname, gname);
	
	PrintBIN(gname); 
	return 0;
}