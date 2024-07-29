#include<iostream>
#include<string>
using namespace std;
struct Student
{
	string name, id;
	double gpa;
};
struct SV
{
	Student s;
	SV *next;
};
typedef struct SV* sv;
sv makeNode() {
	Student s;
	cout << "--> Nhap thong tin sinh vien  " << endl;
	cout << "Nhap ID : "; cin >> s.id;
	cout << "Nhap ten : "; cin.ignore(); getline(cin, s.name);
	cout << "Nhap GPA : "; cin >> s.gpa;
	sv tmp = new SV;
	tmp->s = s;
	tmp->next = NULL;
	return tmp;
}
// Kiểm tra rỗng
bool empty(sv a) {
	return a == NULL;
}
// Đếm có bao nhiêu node trong danh sách
int Size(sv a) {
	int dem = 0;
	while (a != nullptr) {
		dem++;
		a = a->next;// gán địa chỉ của node tiếp theo cho node hiện tại
	}// cho node hiện tại nhảy tới node tiếp theo
	return dem;
}
// Thêm một phần tử vào đầu danh sách liên kết 
void insertFirst(sv& a) {
	sv tmp = makeNode();
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
void insertLast(sv& a) {
	sv tmp = makeNode();
	if (a == NULL) {
		a = tmp;
	}
	else {
		sv p = a;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = tmp;
	}
}
// Thêm một phần tử vào giữa danh sách  
void insertMiddle(sv& a, int pos) {
	int n = Size(a);
	if (pos <= 0 || pos > n + 1) {
		cout << "Vi tri chen khong hop le ! " << endl;
	}
	if (pos == 1) {
		insertFirst(a);
		return;
	}
	else if (pos==n+1) {
		insertLast(a);
		return;
	}
	sv p = a;
	for (int i = 1; i < pos - 1; i++) {
		p = p->next;
	}
	sv tmp = makeNode();
	tmp->next = p->next;
	p->next = tmp;
}
// Xóa phần tử đầu
void deleteFirst(sv& a) {
	if (a == NULL) {
		return;
	}
	a = a->next;
}
// Xóa phần tử cuối
void deleteLast(sv& a) {
	if (a == nullptr) {
		return;
	}
	sv truoc = NULL, sau = a;
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
void deleteMiddle(sv& a, int pos) {
	// vị trí xóa không hợp lệ
	if (pos <= 0 || pos > Size(a)) {
		return;
	}
	sv truoc = NULL, sau = a;
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
void insv(Student s) {
	cout << "--------------------------------" << endl;
	cout << "ID : " << s.id << endl;
	cout << "Ho ten : " << s.name << endl;
	cout << "GPA : " << s.gpa << endl;
	cout << "--------------------------------" << endl;
}
void in(sv a) {
	cout << "--------------------------------" << endl;
	cout << "Danh sach sinh vien !!! " << endl;
	while (a != NULL) {
		insv(a->s);
		a = a->next;
	}
	cout << endl;
	cout << "--------------------------------" << endl;
}
void sapxepGPA(sv& a) {
	//selection sort
	for (sv p = a; p->next != NULL; p = p->next) {
		sv min = p;
		for (sv q = p->next; q != NULL; q = q->next) {
			if (q->s.gpa < min->s.gpa) {
				min = q;
			}
		}
		Student tmp = min->s;
		min->s = p->s;
		p->s = tmp;
	}
}
int main() {
	sv head = nullptr;
	int pos;
	int x;
	while (true)
	{
		cout << "-----------------MENU------------------" << endl;
		cout << "1. chen sinh vien dau vao danh sach " << endl;
		cout << "2. chen sinh vien vao cuoi danh sach " << endl;
		cout << "3. chen sinh vien vao giua danh sach " << endl;
		cout << "4. xoa phan tu o dau " << endl;
		cout << "5. xoa phan tu o cuoi " << endl;
		cout << "6. xoa phan tu o giua " << endl;
		cout << "7. duyet danh sach lien ket " << endl;
		cout << "8. Sap xep cac cac sinh vien trong danh sach lien ket tang dan" << endl;
		cout << "0. thoat " << endl;
		cout << "---------------------------------------" << endl;
		cout << "Lua chon : "; int luachon; cin >> luachon;
		switch (luachon)
		{
		case 0:
			return 0;
			break;
		case 1:
			insertFirst(head);
			break;
		case 2:
			insertLast(head);
			break;
		case 3:
			cout << "Nhap vi tri can chen : ";  cin >> pos;
			insertMiddle(head, pos);
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
			sapxepGPA(head);
		}
	}
	system("pause");
	return 0;
}