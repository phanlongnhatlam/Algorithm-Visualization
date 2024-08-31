#include "graphics.h"
#include <windows.h>
#include<iostream>
#include <cstdlib>
#pragma comment(lib, "graphics.lib")
using namespace std;
// Hàm vẽ mảng
void drawArray(int a[], int n, int l = -1, int r = -1, int i = -1, int j = -1,  bool sorted = false, int pivot = -1) {
    int left = 50, top = 150;
    int right = 150, bottom = 250;
    char giatri[10];
    for (int k = 0; k < n; k++) {
        if (sorted) {
            setfillstyle(SOLID_FILL, GREEN);  // Màu xanh lá cho tất cả phần tử sau khi sắp xếp xong
        }
        else if (k == i || k == j) {
            setfillstyle(SOLID_FILL, RED);  // Màu đỏ khi con trỏ i hoặc j đi qua
        }
        else {
            setfillstyle(SOLID_FILL, BLACK);  // Màu đen cho tất cả các phần tử khác
        }
        bar(left, top, right, bottom);
        sprintf_s(giatri, "%d", a[k]);
        double giatri_x = left + (right - left) / 2 - 5;
        double giatri_y = top + (bottom - top) / 2.5;
        outtextxy(giatri_x, giatri_y, giatri);
        rectangle(left, top, right, bottom);
        left += 100;
        right += 100;
    }
    // Hiển thị chữ Pivot
    if (pivot != -1) {
        char pivotText[20];
        sprintf_s(pivotText, "Pivot: %d", pivot);
        outtextxy(50, 300, pivotText);  
    }
}
// Hàm nhấp nháy trước khi hoán đổi
void blinkBeforeSwap(int left1, int right1, int left2, int right2, int top, int bottom, int a[], int i, int j) {
    for (int b = 0; b < 2; b++) {
        setfillstyle(SOLID_FILL, YELLOW);
        bar(left1, top, right1, bottom);
        bar(left2, top, right2, bottom);
        char giatri[10];
        sprintf_s(giatri, "%d", a[i]);
        double giatri_x1 = left1 + (right1 - left1) / 2 - 5;
        double giatri_y1 = top + (bottom - top) / 2.5;
        outtextxy(giatri_x1, giatri_y1, giatri);
        sprintf_s(giatri,"%d", a[j]);
        double giatri_x2 = left2 + (right2 - left2) / 2 - 5;
        double giatri_y2 = top + (bottom - top) / 2.5;
        outtextxy(giatri_x2, giatri_y2, giatri);
        rectangle(left1, top, right1, bottom);
        rectangle(left2, top, right2, bottom);
        delay(300);

        setfillstyle(SOLID_FILL, BLACK);
        bar(left1, top, right1, bottom);
        bar(left2, top, right2, bottom);
        sprintf_s(giatri, "%d", a[i]);
        outtextxy(giatri_x1, giatri_y1, giatri);
        sprintf_s(giatri, "%d", a[j]);
        outtextxy(giatri_x2, giatri_y2, giatri);
        rectangle(left1, top, right1, bottom);
        rectangle(left2, top, right2, bottom);
        delay(300);
    }
}

// Hàm phân vùng
int partition(int a[], int l, int r, int luachon) {
    int pivot = a[l];
    int i = l - 1, j = r + 1;

    while (true) {
        // tăng dần
        if (luachon == 1) {
            do {
                ++i;
                drawArray(a, r + 1, l, r, i, j,  false, pivot);
                delay(500);  
            } while (a[i] < pivot);

            do {
                --j;
                drawArray(a, r + 1, l, r, i, j, false, pivot);
                delay(500);  
            } while (a[j] > pivot);
        }
        // giảm dần
        else {
            do {
                ++i;
                drawArray(a, r + 1, l, r, i, j,  false, pivot);
                delay(500);  
            } while (a[i] > pivot);

            do {
                --j;
                drawArray(a, r + 1, l, r, i, j, false, pivot);
                delay(500);  
            } while (a[j] < pivot);
        }

        if (i < j) {
            int left_i = 50 + i * 100;
            int right_i = 150 + i * 100;
            int left_j = 50 + j * 100;
            int right_j = 150 + j * 100;

            // Nhấp nháy màu vàng trước khi hoán đổi
            blinkBeforeSwap(left_i, right_i, left_j, right_j, 150, 250, a, i, j);

            // Hoán đổi giá trị
            swap(a[i], a[j]);

            // Vẽ lại mảng sau khi hoán đổi (nhấp nháy-> vàng -> vẽ lại -> đen)
            drawArray(a, r + 1, l, r, -1, -1,  false, pivot);
            delay(500);
        }
        else {
            // Vẽ lại mảng ( đỏ -> đen )
            drawArray(a, r + 1, l, r, -1, -1, false, pivot);
            return j;
        }
    }
}

// Hàm quickSort
void quickSort(int a[], int l, int r, int luachon) {
    if (l >= r) {
        return;
    }
    drawArray(a, r + 1, l, r, -1, -1, false, a[l]);
    delay(500);
    int p = partition(a, l, r, luachon);
    quickSort(a, l, p, luachon);
    quickSort(a, p + 1, r, luachon);
}

int main() {
    int luachon;
    cout << "Ban muon sap xep tang dan hay giam dan?" << endl;
    cout << "1. Tang dan" << endl;
    cout << "2. Giam dan" << endl;
    cout << "Lua chon cua ban: ";
    cin >> luachon;
    initwindow(1000, 600, "QuickSort Visualization");
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    char vanban[] = "QuickSort";
    outtextxy(400, 50, vanban);
    const int n = 8;
    int a[n] = {};
    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 50;
    }
    drawArray(a, n, -1, -1, -1, -1, false,-1);
    delay(1000);
    quickSort(a, 0, n - 1, luachon);
    drawArray(a, n, -1, -1, -1, -1, true, -1);
    getch();
    closegraph();
    return 0;
}
