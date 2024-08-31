#include "graphics.h"
#include <windows.h>
#include <iostream>
#pragma comment(lib, "graphics.lib")
using namespace std;
const int MAX_SIZE = 6;
struct ArrQueue {
    int front, rear;
    int capacity;
    int* Q;
    ArrQueue(int cap = 6) 
    {
        Q = new int[cap];
        capacity = cap;
        front = rear = -1;
    }
    bool isEmpty() 
    {
        return (front == -1);
    }

    bool isFull() 
    {
        return (rear - front == -1) || (rear - front == capacity - 1);
    }
    void EnQueue(int x) 
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
            cout << "Hang doi da day!!!" << endl;
        }
    }
    int DeQueue() 
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
    // số lượng phần tử có trong hàng đợi
    int getSize() 
    {
        if (isEmpty()) return 0;
        if (rear >= front) return rear - front + 1;
        return capacity - front + rear + 1;
    }
};
// Vẽ phần tử hàng đợi
void vePhanTu(int trai, int tren, int phai, int duoi, int giatri)
{
    setfillstyle(SOLID_FILL, BLACK); 
    bar(trai, tren, phai, duoi);      
    char giatri_txt[10];
    sprintf_s(giatri_txt, "%d", giatri);
    rectangle(trai, tren, phai, duoi);    // Vẽ khung hình chữ nhật
    outtextxy(trai + 20, tren + 10, giatri_txt); // Vẽ giá trị của phần tử
}
// Xóa phần tử : tô đen hết 
void xoaPhanTu(int trai, int tren, int phai, int duoi) 
{
    setfillstyle(SOLID_FILL, BLACK); 
    bar(trai, tren, phai, duoi);      
    rectangle(trai, tren, phai, duoi);
}
// Vẽ toàn bộ hàng đợi
void veQueue(ArrQueue& q, int trai, int tren, int phai, int duoi)
{
    int index = q.front;
    int soLuongPhanTu = q.getSize();
    for (int i = 0; i < MAX_SIZE; i++) 
    {
        if (index != -1) 
        {
            vePhanTu(trai + i * 100, tren, phai + i * 100, duoi, q.Q[index]);
            index++;
            if (index >= q.capacity) {
                index = 0;
            }
        }
        else 
        {
            xoaPhanTu(trai + i * 100, tren, phai + i * 100, duoi); // Xóa phần tử (ô trống)
        }
    }
}
// Thêm phần tử vào hàng đợi
void enqueueQueue(ArrQueue& q, int giatri, int& trai, int& phai, int tren, int duoi) 
{
    if (!q.isFull()) 
    {
        q.EnQueue(giatri);
        // Vẽ phần tử mới tại vị trí sau rear
        int rearIndex = q.rear;
        int rearPosition = (trai + rearIndex * 100); // Tính vị trí dựa trên rear
        vePhanTu(rearPosition, tren, rearPosition + 100, duoi, giatri);

    }
    else 
    {
        cout << "Hang doi da day !!!" << endl;
    }
}
// Xóa phần tử khỏi hàng đợi
void dequeueQueue(ArrQueue& q, int& trai, int& phai, int tren, int duoi) 
{
    if (!q.isEmpty()) 
    {
        // Chỉ xóa phần tử tại vị trí đầu tiên
        int indexToDelete = q.front;
        xoaPhanTu(trai + indexToDelete * 100, tren, phai + indexToDelete * 100, duoi);
        q.DeQueue();
    }
    else 
    {
        cout << "Hang doi rong !!! " << endl;
    }
}
// Hàm vẽ tiêu đề
void veTieuDe() 
{
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    outtextxy(250, 20, (char*)"Queue Visualization");
}
int main() 
{
    initwindow(1000, 600, "Queue Visualization");
    ArrQueue q(MAX_SIZE);
    int trai = 100, phai = 200;
    int tren = 200, duoi = 250;
    veTieuDe();
    veQueue(q, trai, tren, phai, duoi);
    int choice;
    int value;
    do {
        system("cls");
        cout << "=============MENU============" << endl;
        cout << "0.Thoat chuong trinh" << endl;
        cout << "1.Enqueue" << endl;
        cout << "2.Dequeue" << endl;
        cout << "=============================" << endl;
        cout << "Lua chon cua ban : ";
        cin >> choice;
        switch (choice) {
        case 1:
            system("cls");
            cout << "Nhap gia tri can enqueue: ";
            cin >> value;
            enqueueQueue(q, value, trai, phai, tren, duoi);
            break;
        case 2:
            system("cls");
            dequeueQueue(q, trai, phai, tren, duoi);
            break;
        case 0:
            system("cls");
            cout << "Thoat chuong trinh." << endl;
            break;
        default:
            system("cls");
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
            break;
        }
        delay(500);
    } while (choice != 0);
    system("pause");
    closegraph();
    return 0;
}
