#include"graphics.h"
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
        sprintf_s(giatri, "%d", a[i]);
        double giatri_x = trai + (phai - trai) / 2 - 5;
        double giatri_y = tren + (duoi - tren) / 2.5;
        outtextxy(giatri_x, giatri_y, giatri);
        sprintf_s(text, "%d", i);
        int text_x = trai + (phai - trai) / 2 - 5;
        int text_y = duoi + 10;
        outtextxy(text_x, text_y, text);
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

// Hàm thực hiện thuật toán sắp xếp đổi chỗ trực tiếp với minh họa
void sapXepDoiChoTrucTiep(int a[], int n, int luachon) {
    int trai = 50, tren = 100;
    int phai = 150, duoi = 150;
    char giatri[10];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int trai_i = 50 + i * 100;
            int phai_i = 150 + i * 100;
            int trai_j = 50 + j * 100;
            int phai_j = 150 + j * 100;

            // Nhấp nháy màu vàng cho hai phần tử đang so sánh
            nhapNhayHinhChuNhat(trai_i, tren, phai_i, duoi, a[i]);
            nhapNhayHinhChuNhat(trai_j, tren, phai_j, duoi, a[j]);

            delay(500);

            // So sánh và hoán đổi nếu cần
            if ((luachon == 1 && a[i] > a[j]) || (luachon == 2 && a[i] < a[j])) {
                setfillstyle(SOLID_FILL, YELLOW);
                bar(trai_i, tren, phai_i, duoi);
                sprintf_s(giatri, "%d", a[i]);
                double giatri_x = trai_i + (phai_i - trai_i) / 2 - 5;
                double giatri_y = tren + (duoi - tren) / 2.5;
                outtextxy(giatri_x, giatri_y, giatri);
                rectangle(trai_i, tren, phai_i, duoi);

                setfillstyle(SOLID_FILL, YELLOW);
                bar(trai_j, tren, phai_j, duoi);
                sprintf_s(giatri, "%d", a[j]);
                giatri_x = trai_j + (phai_j - trai_j) / 2 - 5;
                giatri_y = tren + (duoi - tren) / 2.5;
                outtextxy(giatri_x, giatri_y, giatri);
                rectangle(trai_j, tren, phai_j, duoi);

                delay(500);

                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;

                setfillstyle(SOLID_FILL, BLACK);
                bar(trai_i, tren, phai_i, duoi);
                sprintf_s(giatri, "%d", a[i]);
                giatri_x = trai_i + (phai_i - trai_i) / 2 - 5;
                giatri_y = tren + (duoi - tren) / 2.5;
                outtextxy(giatri_x, giatri_y, giatri);
                rectangle(trai_i, tren, phai_i, duoi);

                setfillstyle(SOLID_FILL, BLACK);
                bar(trai_j, tren, phai_j, duoi);
                sprintf_s(giatri, "%d", a[j]);
                giatri_x = trai_j + (phai_j - trai_j) / 2 - 5;
                giatri_y = tren + (duoi - tren) / 2.5;
                outtextxy(giatri_x, giatri_y, giatri);
                rectangle(trai_j, tren, phai_j, duoi);

                delay(500);
            }
            else {
                setfillstyle(SOLID_FILL, BLACK);
                bar(trai_i, tren, phai_i, duoi);
                sprintf_s(giatri, "%d", a[i]);
                double giatri_x = trai_i + (phai_i - trai_i) / 2 - 5;
                double giatri_y = tren + (duoi - tren) / 2.5;
                outtextxy(giatri_x, giatri_y, giatri);
                rectangle(trai_i, tren, phai_i, duoi);

                setfillstyle(SOLID_FILL, BLACK);
                bar(trai_j, tren, phai_j, duoi);
                sprintf_s(giatri, "%d", a[j]);
                giatri_x = trai_j + (phai_j - trai_j) / 2 - 5;
                giatri_y = tren + (duoi - tren) / 2.5;
                outtextxy(giatri_x, giatri_y, giatri);
                rectangle(trai_j, tren, phai_j, duoi);
            }
        }

        // Làm nổi bật phần đã sắp xếp
        setfillstyle(SOLID_FILL, GREEN);
        int trai_da_sap_xep = 50 + i * 100;
        int phai_da_sap_xep = 150 + i * 100;
        bar(trai_da_sap_xep, tren, phai_da_sap_xep, duoi);
        sprintf_s(giatri, "%d", a[i]);
        double giatri_x = trai_da_sap_xep + (phai_da_sap_xep - trai_da_sap_xep) / 2 - 5;
        double giatri_y = tren + (duoi - tren) / 2.5;
        outtextxy(giatri_x, giatri_y, giatri);
        rectangle(trai_da_sap_xep, tren, phai_da_sap_xep, duoi);
    }

    // Làm nổi bật phần tử cuối cùng nếu đã sắp xếp
    setfillstyle(SOLID_FILL, GREEN);
    int trai_cuoi = 50 + (n - 1) * 100;
    int phai_cuoi = 150 + (n - 1) * 100;
    bar(trai_cuoi, tren, phai_cuoi, duoi);
    sprintf_s(giatri, "%d", a[n - 1]);
    double giatri_x = trai_cuoi + (phai_cuoi - trai_cuoi) / 2 - 5;
    double giatri_y = tren + (duoi - tren) / 2.5;
    outtextxy(giatri_x, giatri_y, giatri);
    rectangle(trai_cuoi, tren, phai_cuoi, duoi);
}

int main() {
    int luachon;
    cout << "Ban muon sap xep tang dan hay giam dan?" << endl;
    cout << "1. Tang dan" << endl;
    cout << "2. Giam dan" << endl;
    cout << "Lua chon cua ban: "; cin >> luachon;

    initwindow(1000, 500, "Chuong trinh");
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    char vanban[] = "Interchange Sort";
    outtextxy(375, 50, vanban);

    const int n = 8;

    int a[n] = {};
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 50;
    }

    veMang(a, n, 50, 100, 150, 150);

    sapXepDoiChoTrucTiep(a, n, luachon);

    getch();
    closegraph();
    return 0;
}
