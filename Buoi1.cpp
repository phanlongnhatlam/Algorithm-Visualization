#include "SLL.h"
const int MAX = 100;
// BAI TAP 1
void Nhap(int* a, int& n) {
	cout << "Nhap so phan tu cua mang : "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << " A[" << i << "] = "; cin >> a[i];
	}
}
void Xuat(int* a, int n) {
	cout << "--> Cac phan tu trong mang " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << " A[" << i << "] = " << a[i] << endl;
	}
}
int Find(int* a, int n, int x) {
	int index = 0;
	while (index < n&& a[index] != x) {
		index++;
	}
	if (index == n) {
		return -1;
	}
	return index;
}
void Add(int* a, int& n, int pos) {
	if (pos<0 || pos > n) {
		cout << "Vi tri chen phan tu khong hop le !!! " << endl;
		return;
	}
	cout << "Moi ban nhap gia tri phan tu ban muon chen vao : "; int x; cin >> x;
	n++;
	for (int i = n - 1; i > pos; i--) {
		a[i] = a[i - 1];
	}
	a[pos] = x;
	cout << "Them thanh cong !!! " << endl;
}
void Delete(int* a, int& n, int pos) {
	if (pos<0 || pos > n - 1) {
		cout << "Vi tri xoa phan tu khong hop le !!! " << endl;
		return;
	}
	n--;
	int i = 0;
	for (int i = pos; i < n; i++) {
		a[i] = a[i + 1];
	}
	cout << "Xoa thanh cong !!! " << endl;
}
void Find_Delete(int* a, int& n, int x) {
	if (Find(a, n, x) == -1) {
		cout << "Khong tim thay " << x << " !!! " << endl;
		return;
	}
	Delete(a, n, Find(a, n, x));
	cout << "Xoa thanh cong !!! " << endl;
}
void bai1() {
	int a[MAX], n, x;
	int bien;
	bool flag = false;
	do {
		system("cls");
		cout << "0.Dung chuong trinh " << endl;
		cout << "1.Nhap danh sach" << endl;
		cout << "2.Xuat danh sach" << endl;
		cout << "3.Tim mot phan tu trong danh sach" << endl;
		cout << "4.them mot phan tu vao trong danh sach" << endl;
		cout << "5.Xoa phan tu tai mot vi tri" << endl;
		cout << "6.Tim va xoa phan tu co trong danh sach" << endl;
		cout << "Lua chon : ";
		cin >> bien;
		switch (bien)
		{
		case 0:
			system("cls");
			break;
		case 1:
			system("cls");
			Nhap(a, n);
			flag = true;
			break;
		case 2:
			system("cls");
			if (flag == false) {
				cout << "Xin moi ban nhap gia tri vao danh sach truoc tien !!! " << endl;
				system("pause");
			}
			else {
				Xuat(a, n);
				system("pause");
			}
			break;
		case 3:
			system("cls");
			cout << "Nhap gia tri can tim : ";  cin >> x;
			if (Find(a, n, x) == -1)
			{
				cout << "Khong tim thay " << x << " !!! " << endl;
			}
			else
				cout << "Tim thay tai vi tri " << Find(a, n, x) << endl;
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "Nhap vi tri can chen : ";  cin >> x;
			Add(a, n, x);
			system("pause");
			break;
		case 5:
			system("cls");
			cout << "Nhap vi tri can xoa : ";  cin >> x;
			Delete(a, n, x);
			system("pause");
			break;
		case 6:
			system("cls");
			cout << "Nhap gia tri can tim va xoa : "; int x; cin >> x;
			Find_Delete(a, n, x);
			system("pause");
			break;
		}
	} while (bien != 0);
	cout << "Dung chuong trinh thanh cong !!!! " << endl;
}
int main()
{
	//bai1();
	SLL danhsach;
	danhsach.InsertLast(1);
	danhsach.InsertLast(1);
	danhsach.InsertLast(1);
	danhsach.DeleteFisrt();
	danhsach.DeleteFisrt();
	danhsach.DeleteFisrt();
	//danhsach.DeleteMiddle();
	danhsach.InDanhSach();
	system("pause");
	return 0;
}