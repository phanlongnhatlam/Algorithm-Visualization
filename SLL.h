#pragma warning(4:4596)
#include<iostream>
using namespace std;
struct Node
{
	int info;
	Node* next;
	Node() {
		info = 0;
		next = 0;
	}
	Node(int x, Node* ptr = 0) {
		info = x;
		next = ptr;
	}
};
struct SLL {
	Node* head;
	SLL() {
		head = 0;
	}
	// kiem tra rong
	bool isEmpty() {
		return (head == NULL);
	}
	// dem trong node co bao nhieu phan tu
	int SLL::dem(Node* a) {
		int dem = 0;
		while (a != nullptr) {
			dem++;
			a = a->next;
		}
		return dem;
	}
	void SLL::InsertFirst(int x) {
		head = new Node(x, head);
	}
	void SLL::InsertMiddle(int x, int pos) {
		if (pos < 0 || pos > dem(head)) {
			cout << "Vi tri chen khong hop le !!! " << endl;
			return;
		}
		if (pos == 0) {
			InsertFirst(x);
		}
		if (pos == dem(head)) {
			InsertLast(x);
		}
		else
		{
			Node* Find = head;
			for (int i = 0; i < pos - 1; i++) {
				Find = Find->next;
			}
			Node* tmp = new Node(x);
			tmp->next = Find->next;
			Find->next = tmp;
		}
	}
	void SLL::InsertLast(int x) {
		if (isEmpty() == true) {
			head = new Node(x, head);
		}
		else
		{
			Node* tmp1 = head;
			while (tmp1->next != nullptr) {
				tmp1 = tmp1->next;
			}
			tmp1->next= new Node(x);
		}
	}
	int SLL::DeleteFisrt() {
		if (isEmpty() == true) {
			cout << "Danh sach rong !!! " << endl;
			return -1;
		}
		Node* tmp = head;
		int phantudaxoa = tmp->info;
		head = head->next;
		delete tmp;
		return phantudaxoa;
	}
	int SLL::DeleteMiddle(int pos) {
		if (isEmpty() == true) {
			cout << "Danh sach rong !!! " << endl;
			return -1;
		}
		if (pos<0 || pos>dem(head) - 1) {
			cout << "Vi tri xoa khong hop le !!! " << endl;
			return -1;
		}
		if (pos == 0) {
			DeleteFisrt();
		}
		else if (pos == dem(head)-1) {
			DeleteLast();
		}
		else
		{	
			Node* run = head;
			// nếu trong danh sách chỉ có một node
			if (run->next == NULL) {
				Node* tmp = run;
				int phantudaxoa = tmp->info;
				head = NULL;
				delete tmp;
				return phantudaxoa;
			}
			else
			{
				for (int i = 0; i < pos - 1; i++) {
					run = run->next;
				}
				Node* tmp = run->next;
				int phantudaxoa = tmp->info;
				run->next = run->next->next;
				delete tmp;
				return phantudaxoa;
			}
		}
	}
	int SLL::DeleteLast() {
		if (isEmpty() == true) {
			cout << "Danh sach rong !!! " << endl;
			return -1;
		}
		Node* truoc = 0;
		Node* sau = head;
		while (sau->next != nullptr) {
			truoc = sau;
			sau = sau->next;
		}
		if (truoc == 0) {
			Node* tmp = sau;
			int phantudaxoa = tmp->info;
			head = nullptr;
			delete tmp;
			return phantudaxoa;		}
		else
		{
			Node* tmp = sau;
			int phantudaxoa = tmp->info;
			truoc->next = nullptr;
			delete tmp;
			return phantudaxoa;
		}
	}
	Node* SLL::Search(int x) {
		Node* tmp = head;
		while (tmp != nullptr && tmp->info != x) {
			tmp = tmp->next;
		}
		return tmp;
	}
	void SLL::InDanhSach() {
		Node* tmp = head;
		if (tmp == NULL) {
			cout << "Danh sach rong !!! " << endl;
		}
		else
		{
			while (tmp != nullptr) {
				cout << tmp->info << endl;
				tmp = tmp->next;
			}
		}
	}
};