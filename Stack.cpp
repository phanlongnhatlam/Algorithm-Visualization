#include "graphics.h"
#include <windows.h>
#include <iostream>
#include <stack>
#pragma comment(lib, "graphics.lib")
using namespace std;

// Hàm vẽ một phần tử của stack
void vePhanTu(int trai, int tren, int phai, int duoi, int giatri) {
    char giatri_txt[10];
    sprintf_s(giatri_txt, "%d", giatri);
    rectangle(trai, tren, phai, duoi);
    outtextxy(trai + 20, tren + 10, giatri_txt);
}

// Hàm vẽ toàn bộ stack
void veStack(stack<int> s, int trai, int tren, int phai, int duoi) {
    while (!s.empty()) {
        vePhanTu(trai, tren, phai, duoi, s.top());
        s.pop();
        tren -= 50;  // Di chuyển vị trí để vẽ phần tử tiếp theo
        duoi -= 50;
    }
}

// Hàm thêm phần tử vào stack
void pushStack(stack<int>& s, int giatri, int& tren, int& duoi, int trai, int phai) {
    s.push(giatri);
    vePhanTu(trai, tren, phai, duoi, giatri);
    tren -= 50;
    duoi -= 50;
}

// Hàm xóa phần tử khỏi stack
void popStack(stack<int>& s, int& tren, int& duoi, int trai, int phai) {
    if (!s.empty()) {
        tren += 50;
        duoi += 50;
        s.pop();

        // Vẽ lại stack sau khi xóa phần tử
        cleardevice();  // Xóa màn hình
        char vanban[] = "Stack Visualization";
        settextstyle(BOLD_FONT, HORIZ_DIR, 2);
        outtextxy(250, 20, vanban);
        veStack(s, trai, tren, phai, duoi);
    }
    else {
        outtextxy(200, 50, (char*)"Stack rong, khong the pop!");
    }
}

int main() {
    initwindow(800, 600, "Stack Visualization");

    stack<int> s;
    int trai = 300, phai = 400;
    int tren = 500, duoi = 550;

    char vanban[] = "Stack Visualization";
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    outtextxy(250, 20, vanban);

    int choice;
    int value;

    do {
        cout << "Lua chon: 1. Push | 2. Pop | 0. Thoat: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Nhap gia tri can push: ";
            cin >> value;
            pushStack(s, value, tren, duoi, trai, phai);
            break;
        case 2:
            popStack(s, tren, duoi, trai, phai);
            break;
        case 0:
            cout << "Thoat chuong trinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
            break;
        }

        delay(500);  // Để dễ quan sát

    } while (choice != 0);

    getch();
    closegraph();
    return 0;
}
