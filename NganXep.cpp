#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
typedef struct Node* node;
bool empty(node top) {
	return top == NULL;
}
int getSize(node top) {
	int ans = 0;
	while (top != NULL) {
		++ans;
		top = top->next;
	}
	return ans;
}
node makeNode(int x) {
	node tmp = new Node;
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}
void push(node& top, int x) {
	node tmp = makeNode(x);
	if (top == NULL) {
		top = tmp;
	}
	else
	{
		tmp->next = top;
		top = tmp;
	}
}
void pop(node& top) {
	if (top == NULL) {
		return;
	}
	top = top->next;
}
int getTop(node top) {
	return top->data;
}
int main() {
	node top = NULL;
	long long n; cin >> n;
	while (n) {
		int r = n % 2;
		push(top, r);
		n /= 2;
	}
	while (!empty(top)) {
		cout << getTop(top);
		pop(top);
	}
	system("pause");
	return 0;
}