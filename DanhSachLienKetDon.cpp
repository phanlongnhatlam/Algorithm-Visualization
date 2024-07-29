#include<iostream>
using namespace std;
struct Node
{	
	int data;
	Node *next;
};
typedef struct Node* node;
// Cấp phát động một node mới với dữ liệu là số nguyên x
node makeNode(int x) {
	node tmp = new Node;
	tmp->data = x;
	tmp->next = nullptr;
	return tmp;
}
// Kiểm tra rỗng
bool empty(node a) {
	return a == NULL;
}
// Đếm có bao nhiêu node trong danh sách
int Size(node a) {
	int dem = 0;
	while (a != nullptr) {
		dem++;
		a = a->next;// gán địa chỉ của node tiếp theo cho node hiện tại
	}// cho node hiện tại nhảy tới node tiếp theo
	return dem;
}
// Thêm một phần tử vào đầu danh sách liên kết 
void insertFirst(node &a, int x) {
	node tmp = makeNode(x);
	if (a == NULL) {
		a = tmp;
	}
	else 
	{
		tmp->next = a;
		a = tmp;
	}
}
// Thêm một phần tử vào cuối danh sách
void insertLast(node& a, int x) {
	node tmp = makeNode(x);
	if (a == NULL) {
		a = tmp;
	}
	else {
		node p = a;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = tmp;
	}
}
// Thêm một phần tử vào giữa danh sách  
void insertMiddle(node& a, int x, int pos) {
	int n = Size(a);
	if (pos <= 0 || pos > n + 1) {
		cout << "Vi tri chen khong hop le ! " << endl;
	}
	if (pos == 1) {
		insertFirst(a,x);
		return;
	}
	else if (pos == n + 1) {
		insertLast(a, x);
		return;
	}
	node p = a;
	for (int i = 1; i < pos - 1; i++) {
		p = p->next;
	}
	node tmp = makeNode(x);
	tmp->next = p->next; 
	p->next = tmp;
}
// Xóa phần tử đầu
void deleteFirst(node& a) {
	if (a == NULL) {
		return;
	}
	a = a->next;	
}
// Xóa phần tử cuối
void deleteLast(node& a) {
	if (a == nullptr) {
		return;
	}
	node truoc = NULL, sau = a;
	while (sau->next != NULL) {
		truoc = sau;
		sau = sau->next;
	}
	if (truoc == NULL) {
		a = NULL;
	}
	else
	{
		truoc->next = NULL;
	}
}
// Xóa ở giữa 
void deleteMiddle(node& a, int pos) {
	// vị trí xóa không hợp lệ
	if (pos <= 0 || pos > Size(a)) {
		return;
	}
	node truoc = NULL, sau = a;
	for (int i = 1; i < pos; i++) {
		truoc = sau;
		sau = sau->next;
	}
	if (truoc == NULL) {
		a = a->next;
	}
	else
	{
		truoc->next = sau->next;
	}
}
void in(node a) {
	cout << "--------------------------------" << endl;
	while (a != NULL) {
		cout << a->data << " ";
		a = a->next;
	}
	cout << endl;
	cout << "--------------------------------" << endl;
}
void sapxep(node& a) {
	//selection sort
	for (node p = a; p->next != NULL; p = p->next) {
		node min = p;
		for (node q = p->next; q != NULL; q = q->next) {
			if (q->data < min->data) {
				min = q;
			}
		}
		int tmp = min->data;
		min->data = p->data;
		p->data = tmp;
	}
}
int main() {
	node head = nullptr;
	int pos;
	int x;
	while (true)
	{
		cout << "-----------------MENU------------------" << endl;
		cout << "1. chen phan tu dau vao danh sach " << endl;
		cout << "2. chen phan tu vao cuoi danh sach " << endl;
		cout << "3. chen phan tu vao giua danh sach " << endl;
		cout << "4. xoa phan tu o dau " << endl;
		cout << "5. xoa phan tu o cuoi " << endl;
		cout << "6. xoa phan tu o giua " << endl;
		cout << "7. duyet danh sach lien ket " << endl;
		cout << "8. Sap xep cac phan tu trong danh sach lien ket tang dan" << endl;
		cout << "0. thoat " << endl;
		cout << "---------------------------------------" << endl;
		cout << "Lua chon : "; int luachon; cin >> luachon;
		switch (luachon)
		{
		case 0:
			return 0;
			break;
		case 1:
			cout << "Nhap gia tri can chen : "; cin >> x;
			insertFirst(head, x);
			break;
		case 2:
			cout << "Nhap gia tri can chen : "; cin >> x;
			insertLast(head, x);
			break;
		case 3:
			cout << "Nhap gia tri can chen : "; cin >> x;
			cout << "Nhap vi tri can chen : ";  cin >> pos;
			insertMiddle(head,x,pos);
			break;
		case 4:
			deleteFirst(head);
			break;
		case 5:
			deleteLast(head);
			break;
		case 6:
			cout << "Nhap vi tri can xoa : ";  cin >> pos;
			deleteMiddle(head, pos);
			break;
		case 7:
			in(head);
			break;
		case 8:
			sapxep(head);
		}
	}
	system("pause");
	return 0;
}