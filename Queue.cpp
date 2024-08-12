#include "graphics.h"
#include <windows.h>
#include <iostream>
#include <queue>
#pragma comment(lib, "graphics.lib")
using namespace std;

const int MAX_SIZE = 5;

// vẽ một phần tử hàng đợi
void vePhanTu(int trai, int tren, int phai, int duoi, int giatri) {
    char giatri_txt[10];
    sprintf_s(giatri_txt, "%d", giatri);
    rectangle(trai, tren, phai, duoi);
    outtextxy(trai + 20, tren + 10, giatri_txt);
}

// vẽ toàn bộ hàng đợi
void veQueue(queue<int> q, int trai, int tren, int phai, int duoi) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (!q.empty()) {
            vePhanTu(trai, tren, phai, duoi, q.front());
            q.pop();
        }
        else {
            rectangle(trai, tren, phai, duoi);
        }
        trai += 100;  // Di chuyển vị trí để vẽ phần tử tiếp theo
        phai += 100;
    }
}

//thêm phần tử vào hàng đợi
void enqueueQueue(queue<int>& q, int giatri, int& trai, int& phai, int tren, int duoi) {
    if (q.size() < MAX_SIZE) {
        q.push(giatri);
        cleardevice();
        veQueue(q, trai, tren, phai, duoi);
    }
    else {
        outtextxy(200, 50, (char*)"Queue da day, khong the enqueue!");
    }
}

// xóa phần tử khỏi hàng đợi
void dequeueQueue(queue<int>& q, int& trai, int& phai, int tren, int duoi) {
    if (!q.empty()) {
        q.pop();
        cleardevice();
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

    // Vẽ sẵn 5 ô hàng đợi cố định
    veQueue(q, trai, tren, phai, duoi);

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

        delay(500); 

    } while (choice != 0);

    getch();
    closegraph();
    return 0;
}
