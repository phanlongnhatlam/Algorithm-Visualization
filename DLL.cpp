#include<iostream>
using namespace std;
// khai báo một struct
struct Node {
	int data;
	Node* pre;
	Node* next;
};
// hàm tạo một node trỏ tới rỗng
Node* MakeNode(int x)
{
	Node* tmp = new Node;
	tmp->data = x;
	tmp->pre = NULL;
	tmp->next = NULL;
	return tmp;
}
// hàm đếm các phần tử có trong node
int Dem(Node* head) {
	int dem = 0;
	while (head != NULL) {
		head = head->next;
		dem++;
	}
	return dem;
}
// hàm in danh sách
void InDanhSach(Node* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
// hàm chèn đầu
void InsertFirst(Node*& head, int x) {
	Node* tmp = MakeNode(x);
	if (head == NULL) {
		head = tmp;
	}
	else
	{
		tmp->next = head;
		head->pre = tmp;
		head = tmp;
	}
}
// hàm chèn cuối
void InsertLast(Node*& head, int x) {
	Node* tmp = MakeNode(x);
	if (head == NULL) {
		head = tmp;
	}
	else
	{
		Node* run = head;
		while (run->next != NULL) {
			run = run->next;
		}
		tmp->pre = run;
		run->next = tmp;
	}
}
// hàm chèn giữa
void InsertMiddle(Node*& head, int pos, int x) {
	if (pos<0 || pos>Dem(head)) {
		cout << "Vi tri chen khong hop le !!! " << endl;
		return;
	}
	Node* tmp = MakeNode(x);
	if (pos == 0) {
		InsertFirst(head,x);
	}
	else if (pos == Dem(head)) {
		InsertLast(head, x);
	}
	else
	{
		Node* run = head;
		for (int i = 0; i < pos - 1; i++)
		{
			run = run->next;
		}
		tmp->next = run->next;
		run->next = tmp;
		tmp->pre = run;
		run->next->pre = tmp;
	}
}
// hàm xóa đầu
int DeleteFirst(Node*& head)
{
	if (head == NULL) {
		cout << "Danh sach rong !!! " << endl;
		return -1;
	}
	Node* tmp = head;
	int phantudaxoa = tmp->data;
	head = head->next;
	delete tmp;
	return phantudaxoa;
}
// hàm xóa cuối
int DeleteLast(Node*& head)
{
	if (head == NULL) {
		cout << "Danh sach rong !!! " << endl;
		return -1;
	}
	Node* run = head;
	// nếu trong danh sách chỉ có một node
	if (run->next == NULL) {
		Node* tmp = head;
		int phantudaxoa = tmp->data;
		head = NULL;
		delete tmp;
		return phantudaxoa;
	}
	while (run->next->next != NULL) {
		run = run->next;
	}
	Node* tmp = run->next;
	int phantudaxoa = tmp->data;
	run->next = NULL;
	delete tmp;
	return phantudaxoa;
}
// hàm xóa giữa
int DeleteMiddle(Node*& head, int pos) {
	if (pos < 0 || pos > Dem(head) -1 ) {
		cout << "Vi tri chen khong hop le !!! " << endl;
		return -1;
	}
	if (pos == 0) {
		return DeleteFirst(head);
	}
	else if (pos == Dem(head) - 1) {
		return DeleteLast(head);
	}
	else
	{
		Node* run = head;
		for (int i = 0; i < pos - 1; i++) {
			run = run->next;
		}
		Node* tmp = run->next;
		int phantudaxoa = tmp->data;
		run->next = run->next->next; // run->next trở thành run->next->next
		cout << run->next->data << " " << endl;
		run->next->pre = run;
		delete tmp;
		return phantudaxoa;
	}
}
int main() {
	Node* head =NULL;
	int x,pos;
	int luachon;
	bool flag = false;
	do {
		system("cls");
		cout << "0.Dung chuong trinh" << endl;
		cout << "1.Chen vao dau" << endl;
		cout << "2.Chen vao giua" << endl;
		cout << "3.Chen vao cuoi" << endl;
		cout << "4.Xoa dau" << endl;
		cout << "5.Xoa giua" << endl;
		cout << "6.Xoa cuoi" << endl;
		cout << "7.In danh sach" << endl;
		cout << "Lua chon cua ban : "; cin >> luachon;
		switch (luachon)
		{
		case 0:
			system("cls");
			break;
		case 1:
			system("cls");
			cout << "Nhap gia tri cho x : "; cin >> x;
			InsertFirst(head, x);
			break;
		case 2:
			system("cls");
			cout << "Nhap gia tri cho x : "; cin >> x;
			cout << "Nhap vi tri can chen : "; cin >> pos;
			InsertMiddle(head, pos, x);
			break;
		case 3:
			system("cls");
			cout << "Nhap gia tri cho x : "; cin >> x;
			InsertLast(head, x);
			break;
		case 4:
			system("cls");
			DeleteFirst(head);
			break;
		case 5:
			system("cls");
			cout << "Nhap vi tri can xoa : "; cin >> pos;
			DeleteMiddle(head, pos);
			break;
		case 6:
			system("cls");
			DeleteLast(head);
			break;
		case 7:
			system("cls");
			if (head == NULL) {
				cout << "Danh sach rong !!! " << endl;
				system("pause");
				break;
			}
			InDanhSach(head);
			system("pause");
			break;
		default:
			cout << "Khong co lua chon ban chon, xin moi ban chon lua chon khac !!! " << endl;
			break;
		}
	} while (luachon != 0);
	cout << "Dung chuong trinh thanh cong !!! " << endl;
	system("pause");
	return 0;
}