#include "graphics.h"
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#pragma comment(lib, "graphics.lib")
using namespace std;
// Hàm vẽ mảng
void veMang(int a[], int n, int trai, int tren, int phai, int duoi, int DaSapXep) {
    char giatri[10];
    for (int i = 0; i < n; i++) {
        if (i >= DaSapXep) {  // Những phần tử đã sắp xếp xong
            setfillstyle(SOLID_FILL, GREEN);
        }
        else {
            setfillstyle(SOLID_FILL, BLACK);
        }
        bar(trai, tren, phai, duoi);
        rectangle(trai, tren, phai, duoi);
        sprintf_s(giatri, "%d", a[i]);
        double giatri_x = trai + (phai - trai) / 2 - 5;
        double giatri_y = tren + (duoi - tren) / 2.5;
        outtextxy(giatri_x, giatri_y, giatri);
        trai += 100;
        phai += 100;
    }
}
// Hàm nhấp nháy hình chữ nhật trước khi hoán đổi
void nhapNhayHinhChuNhat(int trai, int tren, int phai, int duoi, int giatri) {
    char giatri_txt[10];
    sprintf_s(giatri_txt, "%d", giatri);
    double giatri_x = trai + (phai - trai) / 2 - 5;
    double giatri_y = tren + (duoi - tren) / 2.5;

    for (int k = 0; k < 2; k++) {
        setfillstyle(SOLID_FILL, YELLOW); // Nhấp nháy màu vàng
        bar(trai, tren, phai, duoi);
        outtextxy(giatri_x, giatri_y, giatri_txt);
        rectangle(trai, tren, phai, duoi);
        delay(150);

        setfillstyle(SOLID_FILL, BLACK); // Quay lại màu đen
        bar(trai, tren, phai, duoi);
        outtextxy(giatri_x, giatri_y, giatri_txt);
        rectangle(trai, tren, phai, duoi);
        delay(150);
    }
}

// Hàm heapify cho một cây con có gốc là node i
void heapify(int arr[], int n, int i, int DaSapXep, bool tangDan) {
    int largest = i;  // Khởi tạo largest là gốc
    int l = 2 * i + 1;  // left = 2*i + 1
    int r = 2 * i + 2;  // right = 2*i + 2

    // Điều kiện so sánh dựa trên lựa chọn tăng dần hoặc giảm dần
    // tăng dần -> max heap
    if (tangDan) {
        if (l < n && arr[l] < arr[largest]) {
            largest = l;
        }
        if (r < n && arr[r] < arr[largest]) {
            largest = r;
        }
    }
    // giảm dần -> min heap
    else {
        if (l < n && arr[l] > arr[largest]) {
            largest = l;
        }
        if (r < n && arr[r] > arr[largest]) {
            largest = r;
        }
    }

    // Nếu largest không phải là gốc
    if (largest != i) {
        nhapNhayHinhChuNhat(50 + i * 100, 100, 150 + i * 100, 150, arr[i]);
        nhapNhayHinhChuNhat(50 + largest * 100, 100, 150 + largest * 100, 150, arr[largest]);
        swap(arr[i], arr[largest]);

        // Vẽ lại mảng sau khi hoán đổi
        veMang(arr, n, 50, 100, 150, 150, DaSapXep);
        delay(500);

        // Đệ quy heapify cây con bị ảnh hưởng
        heapify(arr, n, largest, DaSapXep, tangDan);
    }
}

// Hàm thực hiện thuật toán Heap Sort với minh họa
void heapSort(int arr[], int n, bool tangDan) {
    // Xây dựng max(min)-heap (sắp xếp lại mảng)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, n, tangDan);
    }
    // duyệt qua từng phần tử
    for (int i = n - 1; i > 0; i--) {
        // Nhấp nháy màu vàng trước khi swap
        nhapNhayHinhChuNhat(50, 100, 150, 150, arr[0]);
        nhapNhayHinhChuNhat(50 + i * 100, 100, 150 + i * 100, 150, arr[i]);
        swap(arr[0], arr[i]);
        // Vẽ lại mảng sau khi hoán đổi, đánh dấu phần tử đã sắp xếp
        veMang(arr, n, 50, 100, 150, 150, i);
        delay(500);
        heapify(arr, i, 0, i, tangDan);
    }
    // Tô màu xanh lá cây cho phần tử cuối cùng
    veMang(arr, n, 50, 100, 150, 150, 0);
}
int main() {
    initwindow(1000, 500, "Heap Sort Visualization");
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    char vanban[] = "Heap Sort";
    outtextxy(375, 50, vanban);
    const int n = 8;
    int arr[n] = {};
    srand((time(0)));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50;
    }
    veMang(arr, n, 50, 100, 150, 150, n);
    bool giamdan = true;
    cout << "Ban muon sap xep tang dan hay giam dan?" << endl;
    cout << "1. Tang dan" << endl;
    cout << "2. Giam dan" << endl;
    cout << "Lua chon cua ban: ";
    int luachon;
    cin >> luachon;
    if (luachon == 1) giamdan = false;
    heapSort(arr, n, giamdan);
    system("pause");
    closegraph();
    return 0;
}
