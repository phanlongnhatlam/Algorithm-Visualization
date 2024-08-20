#include "graphics.h"
#include <windows.h>
#include <iostream>
#include <cstdlib>
#pragma comment(lib, "graphics.lib")
using namespace std;

// Hàm vẽ mảng
void drawArray(int a[], int n, int l = -1, int r = -1, int i = -1, int j = -1, int pivotIndex = -1, bool sorted = false) {
    int left = 50, top = 100;
    int right = 150, bottom = 150;
    char giatri[10];
    for (int k = 0; k < n; k++) {
        if (sorted) {
            setfillstyle(SOLID_FILL, GREEN);  // Màu xanh lá cho tất cả phần tử sau khi sắp xếp xong
        }
        else if (k == pivotIndex) {
            setfillstyle(SOLID_FILL, BLUE);  // Màu xanh dương cho pivot
        }
        else if (k == i || k == j) {
            setfillstyle(SOLID_FILL, RED);  // Màu đỏ khi con trỏ i hoặc j đi qua
        }
        else {
            setfillstyle(SOLID_FILL, BLACK);  // Màu đen cho tất cả các phần tử khác
        }
        bar(left, top, right, bottom);
        sprintf_s(giatri, sizeof(giatri), "%d", a[k]);
        double giatri_x = left + (right - left) / 2 - 5;
        double giatri_y = top + (bottom - top) / 2.5;
        outtextxy(giatri_x, giatri_y, giatri);
        rectangle(left, top, right, bottom);
        left += 100;
        right += 100;
    }
}

// Hàm nhấp nháy trước khi hoán đổi
void blinkBeforeSwap(int left1, int right1, int left2, int right2, int top, int bottom, int a[], int i, int j) {
    for (int b = 0; b < 2; b++) {
        setfillstyle(SOLID_FILL, YELLOW);
        bar(left1, top, right1, bottom);
        bar(left2, top, right2, bottom);
        char giatri[10];
        sprintf_s(giatri, sizeof(giatri), "%d", a[i]);
        double giatri_x1 = left1 + (right1 - left1) / 2 - 5;
        double giatri_y1 = top + (bottom - top) / 2.5;
        outtextxy(giatri_x1, giatri_y1, giatri);
        sprintf_s(giatri, sizeof(giatri), "%d", a[j]);
        double giatri_x2 = left2 + (right2 - left2) / 2 - 5;
        double giatri_y2 = top + (bottom - top) / 2.5;
        outtextxy(giatri_x2, giatri_y2, giatri);
        rectangle(left1, top, right1, bottom);
        rectangle(left2, top, right2, bottom);
        delay(300);

        setfillstyle(SOLID_FILL, BLACK);
        bar(left1, top, right1, bottom);
        bar(left2, top, right2, bottom);
        sprintf_s(giatri, sizeof(giatri), "%d", a[i]);
        outtextxy(giatri_x1, giatri_y1, giatri);
        sprintf_s(giatri, sizeof(giatri), "%d", a[j]);
        outtextxy(giatri_x2, giatri_y2, giatri);
        rectangle(left1, top, right1, bottom);
        rectangle(left2, top, right2, bottom);
        delay(300);
    }
}

// Hàm phân vùng
int partition2(int a[], int l, int r, int luachon) {
    int pivotIndex = l;
    int pivot = a[pivotIndex];
    int i = l - 1, j = r + 1;
    while (true) {
        if (luachon == 1) {
            do {
                ++i;
                drawArray(a, r + 1, l, r, i, j, pivotIndex);  // Hiển thị khi con trỏ i di chuyển
                delay(500);  // Làm chậm quá trình
            } while (a[i] < pivot);

            do {
                --j;
                drawArray(a, r + 1, l, r, i, j, pivotIndex);  // Hiển thị khi con trỏ j di chuyển
                delay(500);  // Làm chậm quá trình
            } while (a[j] > pivot);
        }
        else {
            do {
                ++i;
                drawArray(a, r + 1, l, r, i, j, pivotIndex);  // Hiển thị khi con trỏ i di chuyển
                delay(500);  // Làm chậm quá trình
            } while (a[i] > pivot);

            do {
                --j;
                drawArray(a, r + 1, l, r, i, j, pivotIndex);  // Hiển thị khi con trỏ j di chuyển
                delay(500);  // Làm chậm quá trình
            } while (a[j] < pivot);
        }
        if (i < j) {
            int left_i = 50 + i * 100;
            int right_i = 150 + i * 100;
            int left_j = 50 + j * 100;
            int right_j = 150 + j * 100;

            // Nhấp nháy màu vàng trước khi hoán đổi
            blinkBeforeSwap(left_i, right_i, left_j, right_j, 100, 150, a, i, j);

            // Hoán đổi giá trị và cập nhật vị trí pivot nếu bị hoán đổi
            if (i == pivotIndex) {
                pivotIndex = j;
            }
            else if (j == pivotIndex) {
                pivotIndex = i;
            }
            swap(a[i], a[j]);
            drawArray(a, r + 1, l, r, i, j, pivotIndex);  // Hiển thị sau khi hoán đổi
            delay(500);
        }
        else {
            return j;
        }
    }
}

// Hàm sắp xếp nhanh
void quickSort2(int a[], int l, int r, int luachon) {
    if (l >= r) {
        return;
    }
    drawArray(a, r + 1, l, r, -1, -1, l); // Hiển thị phân đoạn đang sắp xếp với pivot
    delay(500);
    int p = partition2(a, l, r, luachon);
    quickSort2(a, l, p, luachon);
    quickSort2(a, p + 1, r, luachon);
}

int main() {
    int luachon;
    cout << "Ban muon sap xep tang dan hay giam dan ?" << endl;
    cout << "1. Tang dan" << endl;
    cout << "2. Giam dan" << endl;
    cout << "Lua chon cua ban : "; cin >> luachon;

    initwindow(1000, 500, "QuickSort Visualization");
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    char vanban[] = "QuickSort";
    outtextxy(375, 50, vanban);

    const int n = 8;
    int a[n] = {};
    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 50;
    }

    drawArray(a, n);  // Hiển thị ban đầu với màu đen cho tất cả các phần tử
    quickSort2(a, 0, n - 1, luachon);

    // Hiển thị toàn bộ mảng với màu xanh lá sau khi sắp xếp xong
    drawArray(a, n, -1, -1, -1, -1, -1, true);

    getch();
    closegraph();
    return 0;
}
