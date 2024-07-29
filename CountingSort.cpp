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
	cout << "Mang sau khi sap xep : ";
	int m = INT_MIN;
	int cnt[100000] = {};
	// đếm
	for (int i = 0; i < n; i++)
	{
		cnt[a[i]]++;
		m = max(m, a[i]);
	}
	if (luachon == 1)
	{
		for (int i = 0; i <= m; i++)
		{
			if (cnt[i] != 0)
			{
				for (int j = 0; j < cnt[i]; j++)
				{
					cout << i << " ";
				}
			}
		}
	}
	else
	{
		for (int i = m; i >= 0; i--)
		{
			if (cnt[i] != 0)
			{
				for (int j = 0; j < cnt[i]; j++)
				{
					cout << i << " ";
				}
			}
		}
	}
	cout << endl;
	system("pause");
	return 0;
}