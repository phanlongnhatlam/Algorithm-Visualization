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
void nhapNhayHinhChuNhat(int trai, int tren, int phai, int duoi, int giatri) {
    char giatri_txt[10];
    sprintf_s(giatri_txt, "%d", giatri);
    double giatri_x = trai + (phai - trai) / 2 - 5;
    double giatri_y = tren + (duoi - tren) / 2.5;

    for (int k = 0; k < 3; k++) {
        setfillstyle(SOLID_FILL, RED);
        bar(trai, tren, phai, duoi);
        outtextxy(giatri_x, giatri_y, giatri_txt);
        rectangle(trai, tren, phai, duoi);
        delay(150);
        setfillstyle(SOLID_FILL, BLACK);
        bar(trai, tren, phai, duoi);
        outtextxy(giatri_x, giatri_y, giatri_txt);
        rectangle(trai, tren, phai, duoi);
        delay(150);
    }
}

// Hàm heapify cho một cây con có gốc là node i
void heapify(int arr[], int n, int i) {
    int largest = i;  // Khởi tạo largest là gốc
    int l = 2 * i + 1;  // left = 2*i + 1
    int r = 2 * i + 2;  // right = 2*i + 2

    int trai = 50 + i * 100;
    int phai = 150 + i * 100;
    int trai_l = 50 + l * 100;
    int phai_l = 150 + l * 100;
    int trai_r = 50 + r * 100;
    int phai_r = 150 + r * 100;

    // Nếu nút con bên trái lớn hơn gốc
    if (l < n && arr[l] > arr[largest]) {
        nhapNhayHinhChuNhat(trai_l, 100, phai_l, 150, arr[l]);
        largest = l;
    }

    // Nếu nút con bên phải lớn hơn largest
    if (r < n && arr[r] > arr[largest]) {
        nhapNhayHinhChuNhat(trai_r, 100, phai_r, 150, arr[r]);
        largest = r;
    }

    // Nếu largest không phải là gốc
    if (largest != i) {
        nhapNhayHinhChuNhat(trai, 100, phai, 150, arr[i]);
        swap(arr[i], arr[largest]);
        veMang(arr, n, 50, 100, 150, 150);
        delay(500);

        // Đệ quy heapify cây con bị ảnh hưởng
        heapify(arr, n, largest);
    }
}

// Hàm thực hiện thuật toán Heap Sort với minh họa
void heapSort(int arr[], int n) {
    // Xây dựng heap (sắp xếp lại mảng)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Trích xuất từng phần tử từ heap
    for (int i = n - 1; i > 0; i--) {
        // Di chuyển gốc hiện tại đến cuối
        nhapNhayHinhChuNhat(50, 100, 150, 150, arr[0]);
        swap(arr[0], arr[i]);
        veMang(arr, n, 50, 100, 150, 150);
        delay(500);

        // Gọi max heapify trên heap bị giảm
        heapify(arr, i, 0);
    }
}

int main() {
    initwindow(1000, 500, "Heap Sort Visualization");
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    char vanban[] = "Heap Sort";
    outtextxy(375, 50, vanban);

    const int n = 5;

    int arr[n] = {};
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50;
    }

    veMang(arr, n, 50, 100, 150, 150);

    heapSort(arr, n);

    getch();
    closegraph();
    return 0;
}
