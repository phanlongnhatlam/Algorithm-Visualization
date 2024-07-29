#pragma warning(4:4596)
#include<iostream>
using namespace std;
//struct ArrQueue
//{
//	int* Q;
//	int capacity;
//	int front, rear;
//	ArrQueue(int cap = 100)
//	{
//		Q = new int[cap];
//		capacity = cap;
//		front = rear = -1;
//	}
//	bool ArrQueue::isEmpty()
//	{
//		return (front == -1);
//	}
//	bool ArrQueue::isFull()
//	{
//		return (rear - front == capacity - 1) || (rear - front == -1);
//	}
//	void ArrQueue::EnQueue(int x)
//	{
//		if (!isFull())
//		{
//			if (isEmpty())
//			{
//				front = 0;
//			}
//			if (rear == capacity - 1)
//			{
//				rear = -1;
//			}
//			Q[++rear] = x;
//		}
//		else
//		{
//			cout << "Hang doi da day !!! " << endl;
//		}
//	}
//	int ArrQueue::DeQueue()
//	{
//		int x = Q[front];
//		if (rear == front)
//		{
//			rear = front = -1;
//		}
//		else
//		{
//			front++;
//			if (front >= capacity)
//			{
//				front = 0;
//			}
//		}
//		return x;
//	}
//}; 
struct ArrQueue
{
	int front, rear;
	int capacity;
	int* Q;
	ArrQueue(int cap = 100)
	{
		Q = new int[cap];
		capacity = cap;
		front = rear = -1;
	}
	// empty
	bool ArrQueue::isEmpty()
	{
		return (front == -1) ;
	}
	// full
	bool ArrQueue::isFull()
	{
		return (rear - front == -1) || (rear - front == capacity - 1);
	}
	// enqueue
	void ArrQueue::EnQueue(int x)
	{
		if (!isFull())
		{
			if (isEmpty())
			{
				front = 0;
			}
			if (rear == capacity - 1)
			{
				rear = -1;
			}
			Q[++rear] = x;
		}
		else
		{
			cout << "Hang doi  da day !!! " << endl;
		}
	}
	// dequeu
	int ArrQueue::DeQueue()
	{
		int x = Q[front];
		if (rear == front)
		{
			rear = front = -1;
		}
		else
		{
			front++;
			if (front >= capacity)
			{
				front = 0;
			}
		}
		return x;
	}
};
