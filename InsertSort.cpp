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
	for (int i = 1; i < n; i++)
	{
		int x = a[i];
		int pos = i - 1;
		if (luachon == 1)
		{
			while (pos >= 0 && x < a[pos])
			{
				a[pos + 1] = a[pos];
				--pos;
			}
		}
		else
		{
			while (pos >= 0 && x > a[pos])
			{
				a[pos + 1] = a[pos];
				--pos;
			}
		}
		
		a[pos + 1] = x;
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