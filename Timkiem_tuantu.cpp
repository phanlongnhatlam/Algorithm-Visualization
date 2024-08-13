#include "graphics.h"
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#pragma comment(lib, "graphics.lib")
using namespace std;

// Hàm vẽ mảng
void veMang(int a[], int n, int trai, int tren, int phai, int duoi) {
    char giatri[10];
    for (int i = 0; i < n; i++) {
        rectangle(trai, tren, phai, duoi);
        sprintf_s(giatri, "%d", a[i]);
        double giatri_x = trai + (phai - trai) / 2 - 5;
        double giatri_y = tren + (duoi - tren) / 2.5;
        outtextxy(giatri_x, giatri_y, giatri);
        trai += 100;
        phai += 100;
    }
}

// Hàm nhấp nháy hình chữ nhật
void nhapNhayHinhChuNhat(int trai, int tren, int phai, int duoi, int giatri, int color) {
    char giatri_txt[10];
    sprintf_s(giatri_txt, "%d", giatri);
    double giatri_x = trai + (phai - trai) / 2 - 5;
    double giatri_y = tren + (duoi - tren) / 2.5;

    setfillstyle(SOLID_FILL, color);
    bar(trai, tren, phai, duoi);
    outtextxy(giatri_x, giatri_y, giatri_txt);
    rectangle(trai, tren, phai, duoi);
}

// Hàm tìm kiếm tuần tự với minh họa
int timKiemTuanTu(int a[], int n, int key, int trai, int tren, int phai, int duoi) {
    for (int i = 0; i < n; i++) {
        nhapNhayHinhChuNhat(trai + i * 100, tren, trai + i * 100 + 100, duoi, a[i], YELLOW);
        delay(300);

        if (a[i] == key) {
            nhapNhayHinhChuNhat(trai + i * 100, tren, trai + i * 100 + 100, duoi, a[i], GREEN);
            outtextxy(400, duoi + 50, (char*)"Tim thay gia tri trong mang!");
            return i; // Trả về vị trí của số cần tìm
        }
        else {
            nhapNhayHinhChuNhat(trai + i * 100, tren, trai + i * 100 + 100, duoi, a[i], RED);
        }

        delay(300);
    }

    outtextxy(400, duoi + 50, (char*)"Khong tim thay gia tri trong mang!");
    return -1; // Trả về -1 nếu không tìm thấy
}

int main() {
    initwindow(1000, 800, "Sequential Search Visualization");
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    char vanban[] = "Sequential Search";
    outtextxy(400, 50, vanban);

    const int n = 8;
    int a[n];

    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 50;
    }

    veMang(a, n, 50, 100, 150, 150);

    int key;
    cout << "Nhap gia tri can tim: ";
    cin >> key;

    int vitri = timKiemTuanTu(a, n, key, 50, 100, 150, 150);

    if (vitri != -1) {
        cout << "Gia tri " << key << " duoc tim thay o vi tri: " << vitri << endl;
    }
    else {
        cout << "Khong tim thay gia tri " << key << " trong mang." << endl;
    }
    system("pause");
    closegraph();
    return 0;
}
