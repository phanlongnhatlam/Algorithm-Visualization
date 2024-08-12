#include "graphics.h"
#include <windows.h>
#include <iostream>
#pragma comment(lib, "graphics.lib")
using namespace std;
const int MAX_SIZE = 5;  //co dinh phan tu stack
int stack[MAX_SIZE];
int top = -1;  // Vị trí đầu của stack
// Hàm vẽ một phần tử của stack
void vePhanTu(int trai, int tren, int phai, int duoi, int giatri) {
    char giatri_txt[10];
    sprintf_s(giatri_txt, "%d", giatri);
    rectangle(trai, tren, phai, duoi);
    outtextxy(trai + 20, tren + 10, giatri_txt);
}
// Hàm vẽ toàn bộ stack
void veStack(int trai, int tren, int phai, int duoi) {
    cleardevice();
    char vanban[] = "Stack Visualization";
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    outtextxy(250, 20, vanban);
    int currentTop = top;
    // Vẽ từ dưới lên trên, từ stack[0] đến stack[top]
    for (int i = 0; i <= currentTop; i++) {
        vePhanTu(trai, duoi - 50 * (i + 1), phai, duoi - 50 * i, stack[i]);
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
    char vanban[] = "Stack Visualization";
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    outtextxy(250, 20, vanban);
    do {
        cout << "Laa chon: 1. Push | 2. Pop | 0. Thoat: ";
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
