#include"ArrayQueue.h"
int main()
{
	ArrQueue test;
	int luachon;
	int x;
	do {
		system("cls");
		cout << "===================MENU=====================" << endl;
		cout << "0. Dung chuong trinh" << endl;
		cout << "1. Enqueue" << endl;
		cout << "2. Dequeue" << endl;
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
			test.EnQueue(x);
			break;
		case 2:
			system("cls");
			if (test.isEmpty()) {
				cout << "Hang doi rong !!!" << endl;
			}
			else
				cout << test.DeQueue() << endl;
			system("pause");
			break;
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