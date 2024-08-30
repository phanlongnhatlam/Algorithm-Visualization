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
    char text[10];
    for (int i = 0; i < n; i++) {
        rectangle(trai, tren, phai, duoi);
        sprintf_s(giatri, sizeof(giatri), "%d", a[i]);
        double giatri_x = trai + (phai - trai) / 2 - 5;
        double giatri_y = tren + (duoi - tren) / 2.5;
        outtextxy(giatri_x, giatri_y, giatri);
        sprintf_s(text, sizeof(text), "%d", i);
        int text_x = trai + (phai - trai) / 2 - 5;
        int text_y = duoi + 10;
        outtextxy(text_x, text_y, text);
        trai += 100;
        phai += 100;
    }
}
// Hàm tô màu các phần tử đang so sánh
void toMauDangSoSanh(int trai, int tren, int phai, int duoi, int giatri) {
    char giatri_txt[10];
    sprintf_s(giatri_txt, sizeof(giatri_txt), "%d", giatri);
    double giatri_x = trai + (phai - trai) / 2 - 5;
    double giatri_y = tren + (duoi - tren) / 2.5;
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(trai, tren, phai, duoi);
    outtextxy(giatri_x, giatri_y, giatri_txt);
    rectangle(trai, tren, phai, duoi);
}
// Hàm tô màu các phần tử đã kiểm tra nhưng không khớp
void toMauKhongKhop(int trai, int tren, int phai, int duoi, int giatri) {
    char giatri_txt[10];
    sprintf_s(giatri_txt, sizeof(giatri_txt), "%d", giatri);
    double giatri_x = trai + (phai - trai) / 2 - 5;
    double giatri_y = tren + (duoi - tren) / 2.5;
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(trai, tren, phai, duoi);
    outtextxy(giatri_x, giatri_y, giatri_txt);
    rectangle(trai, tren, phai, duoi);
}
// Hàm tìm kiếm nhị phân
bool binarySearch(int a[], int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        toMauDangSoSanh(50 + m * 100, 100, 150 + m * 100, 150, a[m]);
        delay(800);

        if (a[m] == x) {
            // Nếu tìm thấy, tô màu phần tử khớp
            toMauDangSoSanh(50 + m * 100, 100, 150 + m * 100, 150, a[m]);
            return true;
        }
        else {
            // Nếu không tìm thấy, tô màu phần tử không khớp
            toMauKhongKhop(50 + m * 100, 100, 150 + m * 100, 150, a[m]);
            delay(400);
            if (a[m] < x) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
    }
    return false;
}
// Hàm sắp xếp nổi bọt
void BubleSort(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
int main() {
    initwindow(1000, 500, "Binary Search");
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    char vanban[] = "Tim kiem nhi phan";
    outtextxy(350, 50, vanban);
    const int n = 8;
    int a[n] = {};
    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 50;
    }
    BubleSort(a, n);
    veMang(a, n, 50, 100, 150, 150);
    int x;
    cout << "Nhap gia tri can tim: ";
    cin >> x;
    char message[50];
    sprintf_s(message, sizeof(message), "Gia tri can tim la: %d", x);
    outtextxy(350, 350, message);

    if (binarySearch(a, n, x)) {
        sprintf_s(message, sizeof(message), "Tim thay gia tri %d!", x);
        outtextxy(350, 400, message);
    }
    else {
        sprintf_s(message, sizeof(message), "Khong tim thay gia tri %d!", x);
        outtextxy(350, 400, message);
    }
    system("pause");
    closegraph();
    return 0;
}
