#include<iostream>
#include<cstdlib>
#include<vector>
void merge(int* a, int l, int m, int r, bool sapxep)
{
	std::vector<int> x(a + l, a + m + 1);
	std::vector<int> y(a + m + 1, a + r + 1);
	int i = 0, j = 0;
	while (i < x.size() && j < y.size())
	{
		// tăng dần
		if (sapxep == true)
		{
			if (x[i] <= y[j])
			{
				a[l] = x[i];
				++l;
				++i;
			}
			else
			{
				a[l] = y[j];
				++l;
				++j;
			}
		}
		// giảm dần
		else
		{
			if (x[i] >= y[j])
			{
				a[l] = x[i];
				++l;
				++i;
			}
			else
			{
				a[l] = y[j];
				++l;
				++j;
			}
		}
		
	}
	// copy các phần tử còn lại
	while (i < x.size())
	{
		a[l] = x[i];
		++l;
		++i;
	}
	while (j < y.size())
	{
		a[l] = y[j];
		++l;
		++j;
	}
}
void MergeSort(int a[], int l, int r,bool sapxep)
{
	if (l >= r) { return; }
	int m = (l + r) / 2;
	MergeSort(a, l, m, sapxep);
	MergeSort(a, m + 1, r, sapxep);
	merge(a, l, m, r, sapxep);
}
using namespace std;
int main()
{
	bool sapxep = false;
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
	if (luachon == 1)
	{
		sapxep = true;
	}
	MergeSort(a, 0, n - 1,sapxep);
	cout << "Mang sau khi sap xep : ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}