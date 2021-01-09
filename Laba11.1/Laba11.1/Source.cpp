#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;


void CreateBIN(char* fname) // ��������� ����� ������� � �������� �����
{
	ofstream fout(fname, ios::binary); // ������� ���� ��� ������
	char ch; // ������� ����������� � �� ������������ ��������
	string s; // �������� ������������ �����

		cin.get(); // ������� ����� ��������� � ��� �� ���� �������
		cin.sync(); // "����� �����", ���� ��������� ���� ����� �����
		cout << "enter line: "; getline(cin, s); // ����� �����
		for (unsigned i = 0; i < s.length(); i++) // ������� �������� �����
			fout.write((char*)&s[i], sizeof(s[i])); // �������� ������ � ����

	cout << endl;
}
void PrintBIN(char* fname) // ��������� ����� �� �����
{
	ifstream fin(fname, ios::binary); // ������� ���� ��� ����������
	char c; // ���������� ������
	while (fin.read((char*)&c, sizeof(c))) // ���� ����� ��������� ������
	{
		cout << c << endl; // �������� ���� �� �����
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
	string geometry = "��������";
	int n = geometry.length();
	char* char_array = new char[n + 1];

	strcpy(char_array, geometry.c_str());

	ifstream f(fname, ios::binary); // ������� ���� ��� ����������
	ofstream g(gname, ios::binary); // ������� ���� ��� ������
	char c; // ���������� ������
	while (f.read((char*)&c, sizeof(c))) // ���� ����� ��������� ������
	{
		if (!ContainsInArr(char_array, c, n)) {
			g.write((char*)&c, sizeof(c));
		}
	}
}

void fWrite(fstream& f, const int i, const char x)
{
	f.seekp(i * (long)sizeof(char)); // ���������� ��������
	f.write((char*)&x, sizeof(char)); // �������� ��������
}
char fRead(fstream & f, const int i)
{
	char x;
	f.seekg(i * (long)sizeof(char)); // ���������� ��������
	f.read((char*)&x, sizeof(char)); // ��������� ��������
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