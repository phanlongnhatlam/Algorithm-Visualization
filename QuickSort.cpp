#include "graphics.h"
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#pragma comment(lib, "graphics.lib")
using namespace std;

// Hàm vẽ mảng
// Hàm vẽ mảng
void veMang(int a[], bool daSapXep[], int n, int trai, int tren, int phai, int duoi, int pivotIndex = -1) {
    char giatri[10];
    char text[10];
    for (int i = 0; i < n; i++) {
        if (i == pivotIndex) {
            setfillstyle(SOLID_FILL, GREEN); // Tô màu pivot là xanh lá
            bar(trai, tren, phai, duoi);
        }
        else if (daSapXep[i]) {
            setfillstyle(SOLID_FILL, GREEN);
            bar(trai, tren, phai, duoi);
        }
        else {
            setfillstyle(SOLID_FILL, WHITE); // Đặt màu nền trắng
            bar(trai, tren, phai, duoi); // Vẽ nền trắng
            rectangle(trai, tren, phai, duoi); // Vẽ lại viền
        }
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


// Hàm tô màu các phần tử đã sắp xếp
void toMauDaSapXep(int trai, int tren, int phai, int duoi, int giatri) {
    char giatri_txt[10];
    sprintf_s(giatri_txt, sizeof(giatri_txt), "%d", giatri);
    double giatri_x = trai + (phai - trai) / 2 - 5;
    double giatri_y = tren + (duoi - tren) / 2.5;
    setfillstyle(SOLID_FILL, GREEN);
    bar(trai, tren, phai, duoi);
    outtextxy(giatri_x, giatri_y, giatri_txt);
    rectangle(trai, tren, phai, duoi);
}

// Hàm tô màu các phần tử đang so sánh
void toMauDangSoSanh(int trai, int tren, int phai, int duoi, int giatri) {
    char giatri_txt[10];
    sprintf_s(giatri_txt, sizeof(giatri_txt), "%d", giatri);
    double giatri_x = trai + (phai - trai) / 2 - 5;
    double giatri_y = tren + (duoi - tren) / 2.5;
    setfillstyle(SOLID_FILL, RED);
    bar(trai, tren, phai, duoi);
    outtextxy(giatri_x, giatri_y, giatri_txt);
    rectangle(trai, tren, phai, duoi);
}

// Hàm phân đoạn (partition) sử dụng phương pháp Lomuto
int partition(int a[], bool daSapXep[], int low, int high) {
    int pivot = a[high];
    int pivotIndex = high; // Chỉ mục của pivot
    int i = low - 1;

    // Vẽ mảng và đánh dấu pivot với màu xanh lá
    veMang(a, daSapXep, high + 1, 50, 100, 150, 150, pivotIndex);
    delay(500); // Tạm dừng để xem pivot

    for (int j = low; j < high; j++) {
        toMauDangSoSanh(50 + j * 100, 100, 150 + j * 100, 150, a[j]);
        delay(500); // Tạm dừng để xem phần tử đang so sánh

        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
            swap(daSapXep[i], daSapXep[j]);

            // Vẽ lại mảng sau khi hoán đổi
            veMang(a, daSapXep, high + 1, 50, 100, 150, 150, pivotIndex);
            delay(500); // Tạm dừng để xem sự hoán đổi
        }
    }
    swap(a[i + 1], a[high]);
    swap(daSapXep[i + 1], daSapXep[high]);

    // Vẽ lại mảng sau khi di chuyển pivot về đúng vị trí với màu xanh lá
    veMang(a, daSapXep, high + 1, 50, 100, 150, 150, i + 1);
    delay(500); // Tạm dừng để xem sự hoán đổi pivot

    return i + 1;
}

// Hàm thực hiện thuật toán Quick Sort với minh họa
void quickSort(int a[], bool daSapXep[], int low, int high) {
    if (low < high) {
        int pi = partition(a, daSapXep, low, high);

        // Đánh dấu pivot là đã sắp xếp
        daSapXep[pi] = true;

        // Vẽ lại mảng sau khi phân đoạn
        veMang(a, daSapXep, high + 1, 50, 100, 150, 150);
        delay(500); // Tạm dừng để xem sự phân đoạn

        // Đệ quy với phần bên trái của pivot
        quickSort(a, daSapXep, low, pi - 1);

        // Đệ quy với phần bên phải của pivot
        quickSort(a, daSapXep, pi + 1, high);
    }
}

int main() {
    initwindow(1000, 500, "Chương trình sắp xếp nhanh (Quick Sort)");
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    char vanban[] = "Quick Sort";
    outtextxy(350, 50, vanban);

    const int n = 8;
    int a[n] = {};
    bool daSapXep[n] = {};
    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 50;
    }

    veMang(a, daSapXep, n, 50, 100, 150, 150);
    quickSort(a, daSapXep, 0, n - 1);

    // Tô màu tất cả các phần tử đã sắp xếp
    for (int i = 0; i < n; i++) {
        toMauDaSapXep(50 + i * 100, 100, 150 + i * 100, 150, a[i]);
    }

    getch();
    closegraph();
    return 0;
}
