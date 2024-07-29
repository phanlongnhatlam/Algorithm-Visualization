#pragma warning(4:4596)
#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
	Node()
	{
		data = 0;
		next = 0;
	}
	Node(int x, Node* ptr = 0)
	{
		data = x;
		next = ptr;
	}
};
struct IntSLL
{
	Node* head;
	IntSLL()
	{
		head = NULL;
	}
	// Kiểm tra rỗng
	bool IntSLL::isEmpty()
	{
		return (head == NULL);
	}
	// Push -- insertFirst
	void IntSLL::insertFirst(int x)
	{
		head = new Node(x, head);
	}
	// Pop --deleteFirst
	int IntSLL::deleteFirst()
	{
		Node* tmp = head;
		int phantudaxoa = tmp->data;
		head = head->next;
		delete tmp;
		return phantudaxoa;
	}
};
struct LinkedStack
{
	IntSLL S;
	int n;
	LinkedStack()
	{
		n = 0;
	}
	// Rỗng
	bool LinkedStack::isEmpty()
	{
		return (S.isEmpty());
	}
	// Size
	int LinkedStack::Size()
	{
		return n;
	}
	// Top
	int LinkedStack::Top()
	{
		return S.head->data;
	}
	// Push
	void LinkedStack::Push(int x)
	{
		S.insertFirst(x);
		n++;
	}
	// Pop
	int LinkedStack::Pop()
	{
		--n;
		return S.deleteFirst();
	}
};