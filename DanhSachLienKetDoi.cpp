#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* pre;
	Node* next;
};
// tạo một node trỏ tới null ở hai phía pre và next
Node* MakeNode(int x) {
	Node* tmp = new Node;
	tmp->data = x;
	tmp->next = NULL;
	tmp->pre = NULL;
	return tmp;
}
// In danh sách
void InDanhSach(Node* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
// Đếm trong danh sách có bao nhiêu phần tử
int Count(Node* head) {
	int dem = 0;
	while (head != NULL) {
		head = head->next;
		dem++;
	}
	return dem;
}
// hàm chèn đầu 
void InsertFirst(Node *&head, int x) {
	Node* tmp = MakeNode(x);
	tmp->next = head;
	if (head != NULL) {
		head->pre = tmp;
	}
	head = tmp;
}
// hàm chèn cuối
void InsertLast(Node*& head, int x) {
	Node* tmp = MakeNode(x);
	if (head == NULL) {
		head = tmp;
		return;
	}
	else
	{
		Node* run = head;
		while (run->next != NULL) {
			run = run->next;
		}
		run->next = tmp;
		tmp->pre = run;
	}
}
void InsertMiddle(Node *&head, int pos, int x) {
	if (pos<0 || pos>Count(head)) {
		cout << "Vi tri chen khong hop le !!! " << endl;
		return;
	}
	if (pos == 0) {
		InsertFirst(head,x);
	}
	else if (pos == Count(head)) {
		InsertLast(head, x);
	}
	else
	{
		Node* tmp = MakeNode(x);
		Node* run = head;
		for (int i = 0; i < pos-1; i++) {
			run = run->next;
		}
		tmp->next = run->next;
		run->next = tmp;
		run->next->pre = tmp;
		tmp->pre = run;
	}
}
// Xóa đầu
int DeleteFirst(Node*& head) {
	if (head == NULL) {
		cout << "Danh sach rong !!! " << endl;
		return -1;
	}
	else
	{
		Node* tmp = head;
		int phantudaxoa = head->data;
		head = head->next;
		delete tmp;
		return phantudaxoa;
	}
}
// Xóa cuối
int DeleteLast(Node*& head) {
	if (head == NULL) {
		cout << "Danh sach rong !!! " << endl;
		return -1;
	}
	else
	{
		Node* chaytruoc = 0;
		Node* chaysau = head;
		while (chaysau->next != NULL) {
			chaytruoc = chaysau;
			chaysau = chaysau->next;
		}
		// nếu trong danh sách chỉ có một node
		if (chaytruoc == 0) {
			Node* tmp = head;
			int phantudaxoa = head->data;
			head = NULL;
			delete tmp;
			return phantudaxoa;
		}
		else
		{
			Node* tmp = chaysau;
			int phantudaxoa = chaysau->data;
			chaytruoc->next = NULL;
			delete tmp;
			return phantudaxoa;
		}
		
	}
}
// Xóa giữa
int DeleteMiddle(Node*& head, int pos) {
	if (pos<0 || pos>Count(head)-1) {
		cout << "Vi tri xoa khong hop le !!! " << endl;
		return -1;
	}
	if (pos == 0) {
		DeleteFirst(head);
	}
	else if (pos == Count(head)-1) {
		DeleteLast(head);
	}
	else
	{
		Node* run = head;
		for (int i = 0; i < pos-1 ; i++) {
			run = run->next;
		}
		Node* tmp = run->next;
		int phantudaxoa = tmp->data;
		run->next = run->next->next;
		run->next->pre = run;
		delete tmp;
		return phantudaxoa;
	}
}
int main()
{
	Node* head = NULL;
	InsertFirst(head, 1);
	InsertLast(head, 3);
	InsertLast(head, 4);
	DeleteMiddle(head, 1);
	InDanhSach(head);
	system("pause");
	return 0;
}