#include "graphics.h"
#include <windows.h>
#include <iostream>
#pragma comment(lib, "graphics.lib")
using namespace std;

const int MAX_SIZE = 5;  // Cố định số lượng phần tử trong stack
int stack[MAX_SIZE];
int top = -1;  // Vị trí đầu của stack

// Hàm vẽ một phần tử của stack
void vePhanTu(int trai, int tren, int phai, int duoi, int giatri, bool isEmpty) {
    char giatri_txt[10];
    if (isEmpty) {
        sprintf_s(giatri_txt, "");
    }
    else {
        sprintf_s(giatri_txt, "%d", giatri);
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
    if (top == -1) {
        char emptyMessage[] = "Stack dang rong!";
        outtextxy(250, 60, emptyMessage);
    }
    else if (top == MAX_SIZE - 1) {
        char fullMessage[] = "Stack da day!";
        outtextxy(250, 60, fullMessage);
    }

    // Vẽ các phần tử của stack
    for (int i = 0; i < MAX_SIZE; i++) {
        if (i <= top) {
            vePhanTu(trai, duoi - 50 * (i + 1), phai, duoi - 50 * i, stack[i], false);
        }
        else {
            vePhanTu(trai, duoi - 50 * (i + 1), phai, duoi - 50 * i, 0, true);
        }
    }
}

void pushStack(int value) {
    if (top < MAX_SIZE - 1) {
        top++;
        stack[top] = value;
        veStack(300, 500, 400, 550);
    }
    else {
        cout << "Stack da day" << endl;
    }
}

void popStack() {
    if (top >= 0) {
        top--;
        veStack(300, 500, 400, 550);
    }
    else {
        cout << "Stack dang rong" << endl;
    }
}

int main() {
    initwindow(800, 600, "Stack Visualization");

    int choice;
    int value;
    veStack(300, 500, 400, 550);  // Vẽ stack ban đầu với các ô trống

    do {
        cout << "Lua chon: 1. Push | 2. Pop | 0. Thoat: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Nhap gia tri can push: ";
            cin >> value;
            pushStack(value);
            break;
        case 2:
            popStack();
            break;
        case 0:
            cout << "Thoat chuong trinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
            break;
        }
    } while (choice != 0);

    closegraph();
    return 0;
}
