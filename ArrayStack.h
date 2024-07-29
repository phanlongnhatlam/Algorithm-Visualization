#pragma warning(4:4596)
#include<iostream>
using namespace std;
struct ArrayStack
{
	// Khai báo mảng,số lượng chứa,top
	int* S;
	int capacity;
	int top;
	// Constructor
	ArrayStack(int cap = 100)
	{
		S = new int[cap];
		capacity = cap;
		top = -1;
	}
	// Hàm đếm số lượng phần tử có trong stack
	int ArrayStack::Size()
	{
		return (top + 1);
	}
	// Hàm kiểm tra rỗng
	bool ArrayStack::isEmpty()
	{
		return (top < 0);
	}
	// Hàm kiểm tra full
	bool ArrayStack::isFull()
	{
		return (Size()==capacity);
	}
	// Hàm kiếm tra giá trị ở top
	int ArrayStack::Top()
	{
		return S[top];
	}
	// Push : thêm vào -> nối đuôi
	void ArrayStack::Push(int x)
	{
		S[++top] = x;
	}
	// Pop : lấy từng phần tử ở cuối ra
	int ArrayStack::Pop()
	{
		return S[top--];
	}
};

