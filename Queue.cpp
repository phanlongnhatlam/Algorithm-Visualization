#include "graphics.h"
#include <windows.h>
#include <iostream>
#include <queue>
#pragma comment(lib, "graphics.lib")
using namespace std;

// Hàm vẽ một phần tử của hàng đợi
void vePhanTu(int trai, int tren, int phai, int duoi, int giatri) {
    char giatri_txt[10];
    sprintf_s(giatri_txt, "%d", giatri);
    rectangle(trai, tren, phai, duoi);
    outtextxy(trai + 20, tren + 10, giatri_txt);
}

// Hàm vẽ toàn bộ hàng đợi
void veQueue(queue<int> q, int trai, int tren, int phai, int duoi) {
    while (!q.empty()) {
        vePhanTu(trai, tren, phai, duoi, q.front());
        q.pop();
        trai += 100;  // Di chuyển vị trí để vẽ phần tử tiếp theo
        phai += 100;
    }
}

// Hàm thêm phần tử vào hàng đợi
void enqueueQueue(queue<int>& q, int giatri, int& trai, int& phai, int tren, int duoi) {
    q.push(giatri);
    vePhanTu(trai, tren, phai, duoi, giatri);
    trai += 100;
    phai += 100;
}

// Hàm xóa phần tử khỏi hàng đợi
void dequeueQueue(queue<int>& q, int& trai, int& phai, int tren, int duoi) {
    if (!q.empty()) {
        q.pop();

        // Vẽ lại hàng đợi sau khi xóa phần tử
        cleardevice();  // Xóa màn hình
        char vanban[] = "Queue Visualization";
        settextstyle(BOLD_FONT, HORIZ_DIR, 2);
        outtextxy(250, 20, vanban);
        trai = 100;  // Đặt lại vị trí vẽ phần tử đầu tiên
        phai = 200;
        veQueue(q, trai, tren, phai, duoi);
    }
    else {
        outtextxy(200, 50, (char*)"Queue rong, khong the dequeue!");
    }
}

int main() {
    initwindow(1000, 600, "Queue Visualization");

    queue<int> q;
    int trai = 100, phai = 200;
    int tren = 200, duoi = 250;

    char vanban[] = "Queue Visualization";
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    outtextxy(250, 20, vanban);

    int choice;
    int value;

    do {
        cout << "Lua chon: 1. Enqueue | 2. Dequeue | 0. Thoat: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Nhap gia tri can enqueue: ";
            cin >> value;
            enqueueQueue(q, value, trai, phai, tren, duoi);
            break;
        case 2:
            dequeueQueue(q, trai, phai, tren, duoi);
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
