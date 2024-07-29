#pragma warning(4:4596)
#include<iostream>
using namespace std;
struct Node {
	int info;
	Node* next;
	Node() {
		info = 0;
		next = 0;
	}
	Node(int x, Node* ptr = NULL) {
		info = x;
		next = ptr;
	}
};
struct LinkedQueue {
	Node* front;
	Node* rear;
	LinkedQueue()
	{
		front = rear = NULL;
	}
	bool isEmpty()
	{
		return (front == NULL);
	}
	void LinkedQueue::EnQueue(int x)
	{
		Node* tmp = new Node(x);
		if (isEmpty())
		{
			front = tmp;
		}
		else
		{
			rear->next = tmp;
		}
		rear = tmp;
	}
	int LinkedQueue::DeQueue()
	{
		Node* tmp = front;
		int x = front->info;
		front = front->next;
		if (front == NULL)
		{
			rear = NULL;
		}
		delete tmp;
		return x;
	}
}; 
