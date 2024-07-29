#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int luachon;
	const int n = 8;
	int a[n] = {};
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10 + 1;
	}
	cout << "Mang truoc khi sap xep : ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "Ban muon sap xep tang dan hay giam dan ?" << endl;
	cout << "1. Tang dan" << endl;
	cout << "2. Giam dan" << endl;
	cout << "Lua chon cua ban : "; cin >> luachon;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (luachon == 2)
			{
				if (a[j] < a[j + 1])
				{
					swap(a[j], a[j + 1]);
				}
			}
			else
			{
				if (a[j] > a[j + 1])
				{
					swap(a[j], a[j + 1]);
				}
			}
		}
	}
	cout << "Mang sau khi sap xep : ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}