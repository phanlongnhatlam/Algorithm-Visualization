#include<iostream>
using namespace std;
// struct node
struct MyNode
{
	int data;
	MyNode* next;
};
//
int Dem(MyNode*);
//

// tạo một node mới trỏ tới NULL
MyNode* MakeNode(int x) {
	// cấp phát động
	MyNode* tmp = new MyNode;
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}
// chèn vào đầu
void InsertFirst(MyNode *&a, int x) {
	MyNode* tmp = MakeNode(x);
	// Nếu con trỏ head trỏ tới NULL
	if (a == NULL) {
		a = tmp;
	}
	else
	{
		tmp->next = a;
		a = tmp;
	}
}
// chèn vào cuối
void InsertLast(MyNode*& a, int x) {
	MyNode* tmp = MakeNode(x);
	// Nếu con trỏ head trỏ tới NULL
	if (a == NULL) {
		a = tmp;
	}
	else
	{
		MyNode* Find = a;
		while (Find->next != NULL) {
			Find = Find->next;
		}
		Find->next = tmp;
	}
}
// chèn vào giữa
void InsertMiddle(MyNode*& a,int pos, int x) {
	if (pos <=0 || pos>Dem(a)+1) {
		cout << "Vi tri chen khong hop le !!! " << endl;
		return;
	}
	// nếu a==null 
	MyNode* tmp = MakeNode(x);
	if (a == NULL) {
		a = tmp;
		return;
	}
	// nếu vị trí cần chèn là 1 : tương đương chèn đầu
	if (pos == 1) {
		InsertFirst(a,x);
		return;
	}
	// nếu vị trí cần chèn là vị trí tiếp theo sau phần tử cuối : tương đương chèn cuối
	else if (pos == Dem(a) + 1) {
		InsertLast(a,x);
		return;
	}
	// trường hợp còn lại -> khó :v
	else
	{
		MyNode* Find = a;
		// i sẽ chạy tới vị trí thứ pos-2 --> Find sẽ tới node trước vị trí cần chèn 
		for (int i = 1; i < pos-1; i++) {
			Find = Find->next;
		}
		tmp->next = Find->next;
		Find->next = tmp;
	}
}
// Xóa phần tử đầu
void DeleleFirst(MyNode*& a) {
	if (a == NULL) {
		cout << "Danh sach rong !!! " << endl;
		return;
	}
	int phantuxoa=a->data;
	MyNode* tmp = a;
	a = a->next;
	delete tmp;
	cout << phantuxoa ;
}
// Xóa phần tử cuối
void DeleteLast(MyNode*& a) {
	if (a == NULL) {
		cout << "Danh sach rong !!! " << endl;
		return;
	}
	MyNode* truoc = NULL;
	MyNode* sau = a;
	while (sau->next != NULL) {
		truoc = sau;
		sau = sau->next;
	}
	// nếu trong danh sách chỉ có một node
	if (truoc == NULL) {
		MyNode* tmp1 = a;
		a = NULL;
		delete tmp1;
	}
	else {
		// giải phóng 
		int phantuxoa = sau->data;
		MyNode* tmp = sau;
		truoc->next = NULL;
		delete tmp;
		cout << phantuxoa ;
	}
}
// Xóa phần tử giữa
void DeleteMiddle(MyNode*& a,int pos) {
	if (pos <= 0 || pos > Dem(a)) {
		cout << "Vi tri xoa khong hop le !!! " << endl;
		return;
	}
	if (a == NULL) {
		cout << "Danh sach rong !!! " << endl;
		return;
	}
	if (pos == 1) {
		DeleleFirst(a);
		return;
	}
	/*else if (pos == Dem(a)) {
		DeleteLast(a);
		return;
	}*/
	else {
		MyNode* truoc = NULL;
		MyNode* sau = a;
		for (int i = 1; i < pos ; i++) {
			truoc = sau;
			sau = sau->next;
		}
		// nếu trong danh sách chỉ có một node
		if (truoc == NULL) {
			MyNode* tmp1 = a;
			cout << tmp1->data;
			a = NULL;
			delete tmp1;
		}
		else {
			MyNode* tmp = sau;
			cout << tmp->data;
			truoc->next = sau->next;
			// giải phóng
			delete tmp;
		}
	}
}
// hàm đếm trong danh sách có bao nhiêu node
int Dem(MyNode* a) {
	int dem = 0;
	while (a != NULL) {
		dem++;
		a = a->next;
	}
	return dem;
}
// hàm duyệt 
void Duyet(MyNode* a) {
	while (a!= NULL) {
		cout << a->data << " ";
		a = a->next;
	}
}
int main() {
	MyNode* head = NULL;
	for (int i = 3; i > 0; i--) {
		InsertFirst(head,i);
	}
	for (int i = 1; i <= 3; i++) {
		InsertLast(head, i);
	}
	for (int i = 1; i <=1; i++) {
		InsertMiddle(head, 6, 7);
	}
	cout << "Phan tu da xoa : ";
	DeleleFirst(head);
	cout << endl;
	cout << "Phan tu da xoa : ";
	DeleteMiddle(head,3);
	cout << endl;
	cout << "Phan tu da xoa : ";
	DeleteLast(head);
	cout << endl;
	cout << "Phan tu da xoa : ";
	DeleteMiddle(head, 4);
	DeleteMiddle(head, 1);
	cout << endl;
	Duyet(head);
	cout << endl;
	system("pause");
	return 0;
}