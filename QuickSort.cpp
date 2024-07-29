#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
// Phân hoạch Lomuto
int partition(int a[], int l, int r,int luachon)
{
	int pivot = a[r]; // phần tử bên phải cùng
	int i = l - 1;
	for (int j = l; j < r; j++)
	{
		if (luachon == 1)
		{
			if (a[j] <= pivot)
			{
				i++;
				swap(a[i], a[j]);
			}
		}
		else
		{
			if (a[j] >= pivot)
			{
				i++;
				swap(a[i], a[j]);
			}
		}
	}
	// đưa chốt về giữa
	i++;
	swap(a[i], a[r]);
	return i;
}
void quickSort(int a[], int l, int r,int luachon)
{
	if (l >= r)
	{
		return;
	}
	int p = partition(a, l, r,luachon);
	quickSort(a, l, p - 1, luachon);
	quickSort(a, p + 1, r, luachon);
}
// Phân hoạch Hoare
int partition2(int a[], int l, int r,int luachon)
{
	int pivot = a[l];
	int i = l - 1, j = r + 1;
	while (true)
	{
		if (luachon == 1)
		{
			do {
				++i;
			} while (a[i] < pivot);
			do {
				--j;
			} while (a[j] > pivot);
			if (i < j)
			{
				swap(a[i], a[j]);
			}
			else
				return j;
		}
		else
		{
			do {
				++i;
			} while (a[i] > pivot);
			do {
				--j;
			} while (a[j] < pivot);
			if (i < j)
			{
				swap(a[i], a[j]);
			}
			else
				return j;
		}
	}
}
void quickSort2(int a[], int l, int r,int luachon)
{
	if (l >= r)
	{
		return;
	}
	int p = partition2(a, l, r,luachon);
	quickSort2(a, l, p,luachon);
	quickSort2(a, p + 1, r,luachon);
}
int main() {
	int luachon;
	const int n=8;
	int a[n] = {};
	srand(time(0));
	cout << "Mang truoc khi sap xep : ";
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 50;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "Ban muon sap xep tang dan hay giam dan ?" << endl;
	cout << "1. Tang dan" << endl;
	cout << "2. Giam dan" << endl;
	cout << "Lua chon cua ban : "; cin >> luachon;
	cout << "Mang sau khi sap xep : ";
	quickSort2(a, 0, n - 1,luachon);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}