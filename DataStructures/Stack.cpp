#include "graphics.h"
#include <windows.h>
#include <iostream>
#pragma comment(lib, "graphics.lib")
using namespace std;
const int MAX_SIZE = 6; // Cố định số lượng phần tử trong stack
struct ArrayStack {
    int* S;
    int capacity;
    int top;
    // Constructor
    ArrayStack(int cap = 6) {
        S = new int[cap];
        capacity = cap;
        top = -1;
    }
    // Destructor
    ~ArrayStack() {
        delete[] S;
    }
    // Hàm đếm số lượng phần tử có trong stack
    int Size() {
        return (top + 1);
    }

    // Hàm kiểm tra rỗng
    bool isEmpty() {
        return (top < 0);
    }
    // Hàm kiểm tra đầy
    bool isFull() {
        return (Size() == capacity);
    }
    // Hàm kiểm tra giá trị ở top
    int Top() {
        return S[top];
    }
    // Push: thêm vào -> nối đuôi
    void Push(int x) {
        if (!isFull()) {
            S[++top] = x;
        }
        else {
            cout << "Stack da day!!!" << endl;
        }
    }
    // Pop: lấy từng phần tử ở cuối ra
    int Pop() {
        if (!isEmpty()) {
            return S[top--];
        }
        else {
            cout << "Stack dang rong!!!" << endl;
            return -1; // giá trị báo lỗi 
        }
    }
};
ArrayStack stack(MAX_SIZE); // Khởi tạo stack với kích thước MAX_SIZE
// Hàm vẽ một phần tử của stack
void vePhanTu(int trai, int tren, int phai, int duoi, int giatri, bool isEmpty) {
    char giatri_txt[10];
    if (!isEmpty)
    {
        sprintf_s(giatri_txt, "%d", giatri);
    }
    else
    {
        sprintf_s(giatri_txt, "");
    }
    rectangle(trai, tren, phai, duoi);
    // Tính toán để căn giữa giá trị trong ô
    int textWidth = textwidth(giatri_txt);
    int textHeight = textheight(giatri_txt);
    int xCenter = trai + (phai - trai) / 2 - textWidth / 2;
    int yCenter = tren + (duoi - tren) / 2 - textHeight / 2;
    outtextxy(xCenter, yCenter, giatri_txt);
}
// Hàm vẽ toàn bộ stack
void veStack(int trai, int tren, int phai, int duoi) {
    cleardevice();
    char vanban[] = "Stack Visualization";
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    outtextxy(250, 20, vanban);
    // Hiển thị thông báo stack rỗng hoặc đầy ngay dưới tiêu đề
    if (stack.isEmpty())
    {
        char emptyMessage[] = "Stack dang rong!";
        outtextxy(250, 60, emptyMessage);
    }
    else if (stack.isFull())
    {
        char fullMessage[] = "Stack da day!";
        outtextxy(250, 60, fullMessage);
    }

    // Vẽ các phần tử của stack
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (i <= stack.top)
        {
            vePhanTu(trai, duoi - 50 * (i + 1), phai, duoi - 50 * i, stack.S[i], false);
        }
        else
        {
            vePhanTu(trai, duoi - 50 * (i + 1), phai, duoi - 50 * i, 0, true);
        }
    }
}

void pushStack(int value)
{
    stack.Push(value);
    veStack(300, 500, 400, 550);
}
void popStack()
{
    stack.Pop();
    veStack(300, 500, 400, 550);
}
int main() {
    initwindow(800, 600, "Stack Visualization");
    int choice;
    int value;
    veStack(300, 500, 400, 550);
    do {
        system("cls");
        cout << "=============MENU============" << endl;
        cout << "0.Thoat chuong trinh" << endl;
        cout << "1.Push" << endl;
        cout << "2.Pop" << endl;
        cout << "=============================" << endl;
        cout << "Lua chon cua ban : ";
        cin >> choice;
        switch (choice) {
        case 1:
            system("cls");
            cout << "Nhap gia tri can push: ";
            cin >> value;
            pushStack(value);
            break;
        case 2:
            system("cls");
            popStack();
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
    closegraph();
    return 0;
}
