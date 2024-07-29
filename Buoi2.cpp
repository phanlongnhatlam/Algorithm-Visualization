#include"QuanLiSinhVien_SLL.h";
#include"ArrayStack.h"
#include"ArrayQueue.h"
void QuanLiSinhVien()
{
	DSSV danhsach;
	string hoten, mssv, mssv_can_tim;
	double dtb;
	int luachon;
	do {
		system("cls");
		cout << "===================MENU=====================" << endl;
		cout << "0. Dung chuong trinh" << endl;
		cout << "1. Them sinh vien vao dau danh sach" << endl;
		cout << "2. Them sinh vien vao cuoi danh sach" << endl;
		cout << "3. Xoa sinh vien o dau danh sach" << endl;
		cout << "4. Xoa sinh vien o cuoi danh sach" << endl;
		cout << "5. Them sinh vien vao sau sinh vien co MSSV ban nhap" << endl;
		cout << "6. In danh sach sinh vien" << endl;
		cout << "Lua chon cua ban : "; cin >> luachon;
		switch (luachon)
		{
		case 0:
			system("cls");
			break;
		case 1:
			system("cls");
			cout << "Xin moi ban nhap mssv cua sinh vien : "; cin >> mssv;
			cout << "Xin moi ban nhap ho ten cua sinh vien : "; cin.ignore(); getline(cin, hoten);
			cout << "Xin moi ban nhap diem trung binh cua sinh vien : "; cin >> dtb;
			danhsach.them_dau(hoten, mssv, dtb);
			break;
		case 2:
			system("cls");
			cout << "Xin moi ban nhap mssv cua sinh vien : "; cin >> mssv;
			cout << "Xin moi ban nhap ho ten cua sinh vien : "; cin.ignore(); getline(cin, hoten);
			cout << "Xin moi ban nhap diem trung binh cua sinh vien : "; cin >> dtb;
			danhsach.them_cuoi(hoten, mssv, dtb);
			break;
		case 3:
			system("cls");
			danhsach.xoa_dau();
			break;
		case 4:
			system("cls");
			danhsach.xoa_cuoi();
			break;
		case 5:
			system("cls");
			cout << "Xin moi ban nhap mssv cua sinh vien ban can tim va chen sau sinh vien do : "; cin >> mssv_can_tim;
			cout << "Xin moi ban nhap mssv cua sinh vien ban them vao : "; cin >> mssv;
			cout << "Xin moi ban nhap ho ten cua sinh vien ban them vao : "; cin.ignore(); getline(cin, hoten);
			cout << "Xin moi ban nhap diem trung binh cua sinh vien ban them vao : "; cin >> dtb;
			danhsach.them_sau_mssv(hoten, mssv, dtb, mssv_can_tim);
			break;
		case 6:
			system("cls");
			if (danhsach.isEmpty() == true) {
				cout << "Danh sach rong !!! " << endl;
			}
			else
				danhsach.Xuat_DSSV();
			system("pause");
			break;
		default:
			system("cls");
			cout << "Khong co lua chon ban chon, xin moi ban chon lai !!! " << endl;
			break;
		}
	} while (luachon != 0);
	cout << "Chuong trinh da ket thuc !!!" << endl;
}
void NganXep()
{
	ArrayStack NganXep;
	int luachon, x;
	do {
		system("cls");
		cout << "===================MENU=====================" << endl;
		cout << "0. Dung chuong trinh" << endl;
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. In ra phan tu o tren top" << endl;
		cout << "4. Chuyen so thap phan sang nhi phan " << endl;
		cout << "Lua chon cua ban : "; cin >> luachon;
		cout << "============================================" << endl;
		switch (luachon)
		{
		case 0:
			system("cls");
			break;
		case 1:
			system("cls");
			cout << "Xin moi ban nhap gia tri : "; cin >> x;
			NganXep.Push(x);
			break;
		case 2:
			system("cls");
			if (NganXep.isEmpty()) {
				cout << "Stack rong !!! " << endl;
				system("pause");
				break;
			}
			cout << NganXep.Pop() << endl;
			system("pause");
			break;
		case 3:
			system("cls");
			if (NganXep.isEmpty()) {
				cout << "Stack rong !!! " << endl;
				system("pause");
				break;
			}
			cout << NganXep.Top() << endl;
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "Xin moi ban nhap so thap phan : "; cin >> x;
			while (x != 0) {
				NganXep.Push(x % 2);
				x /= 2;
			}
			cout << "So nhi phan la : ";
			while (NganXep.isEmpty() == false) {
				cout << NganXep.Pop();
			}
			cout << endl;
			system("pause");
		default:
			system("cls");
			cout << "Khong co lua chon ban chon, xin moi ban chon lai !!! " << endl;
			break;
		}
	} while (luachon != 0);
	cout << "Chuong trinh da ket thuc !!!" << endl;
}
int main()
{

	system("pause");
	return 0;
}