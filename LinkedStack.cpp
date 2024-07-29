#include"LinkedStack.h"
int main()
{
	LinkedStack NganXep;
	int luachon;
	int x;
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
	system("pause");
	return 0;
}