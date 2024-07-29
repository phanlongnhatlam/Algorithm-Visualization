#include<iostream>
#include<cstdlib>
using namespace std;
void heapify(int a[], int n, int i,int luachon)
{
	int largest = i;
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	// tăng dần
	if (luachon == 1)
	{
		if (left<n && a[left]>a[largest])
		{
			largest = left;
		}
		if (right<n && a[right]>a[largest])
		{
			largest = right;
		}
	}
	// giảm dần
	else
	{
		if (left<n && a[left]<a[largest])
		{
			largest = left;
		}
		if (right<n && a[right]<a[largest])
		{
			largest = right;
		}
	}
	if (largest != i)
	{
		swap(a[i], a[largest]);
		heapify(a, n, largest,luachon);
	}
}
void heapSort(int a[],int n,int luachon)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	// xây dựng max heap
	{
		heapify(a, n, i,luachon);
	}
	// swap gốc với phần tử cuối trong cành
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[i], a[0]);
		heapify(a, i, 0,luachon);
	}
}
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
	heapSort(a, n,luachon);
	cout << "Mang sau khi sap xep : ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}