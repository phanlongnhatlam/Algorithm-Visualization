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

// Hàm nhấp nháy hai hình chữ nhật cùng lúc
void nhapNhayHaiHinhChuNhat(int trai1, int tren1, int phai1, int duoi1, int giatri1,
    int trai2, int tren2, int phai2, int duoi2, int giatri2) {
    char giatri_txt1[10], giatri_txt2[10];
    sprintf_s(giatri_txt1, sizeof(giatri_txt1), "%d", giatri1);
    sprintf_s(giatri_txt2, sizeof(giatri_txt2), "%d", giatri2);
    double giatri_x1 = trai1 + (phai1 - trai1) / 2 - 5;
    double giatri_y1 = tren1 + (duoi1 - tren1) / 2.5;
    double giatri_x2 = trai2 + (phai2 - trai2) / 2 - 5;
    double giatri_y2 = tren2 + (duoi2 - tren2) / 2.5;

    for (int k = 0; k < 3; k++) {
        setfillstyle(SOLID_FILL, YELLOW);
        bar(trai1, tren1, phai1, duoi1);
        outtextxy(giatri_x1, giatri_y1, giatri_txt1);
        rectangle(trai1, tren1, phai1, duoi1);

        bar(trai2, tren2, phai2, duoi2);
        outtextxy(giatri_x2, giatri_y2, giatri_txt2);
        rectangle(trai2, tren2, phai2, duoi2);

        delay(150);

        setfillstyle(SOLID_FILL, BLACK);
        bar(trai1, tren1, phai1, duoi1);
        outtextxy(giatri_x1, giatri_y1, giatri_txt1);
        rectangle(trai1, tren1, phai1, duoi1);

        bar(trai2, tren2, phai2, duoi2);
        outtextxy(giatri_x2, giatri_y2, giatri_txt2);
        rectangle(trai2, tren2, phai2, duoi2);

        delay(150);
    }
}

// Hàm thực hiện thuật toán sắp xếp nổi bọt với minh họa
void sapXepNoiBot(int a[], int n, int luachon) {
    int trai = 50, tren = 100;
    int phai = 150, duoi = 150;
    char giatri[10];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            int trai_j = 50 + j * 100;
            int phai_j = 150 + j * 100;
            int trai_j1 = 50 + (j + 1) * 100;
            int phai_j1 = 150 + (j + 1) * 100;

            // Làm nổi bật hai phần tử đang so sánh
            setfillstyle(SOLID_FILL, RED);
            bar(trai_j, tren, phai_j, duoi);
            sprintf_s(giatri, sizeof(giatri), "%d", a[j]);
            double giatri_x = trai_j + (phai_j - trai_j) / 2 - 5;
            double giatri_y = tren + (duoi - tren) / 2.5;
            outtextxy(giatri_x, giatri_y, giatri);
            rectangle(trai_j, tren, phai_j, duoi);

            setfillstyle(SOLID_FILL, RED);
            bar(trai_j1, tren, phai_j1, duoi);
            sprintf_s(giatri, sizeof(giatri), "%d", a[j + 1]);
            giatri_x = trai_j1 + (phai_j1 - trai_j1) / 2 - 5;
            giatri_y = tren + (duoi - tren) / 2.5;
            outtextxy(giatri_x, giatri_y, giatri);
            rectangle(trai_j1, tren, phai_j1, duoi);

            delay(500);

            // So sánh và hoán đổi nếu cần
            if ((luachon == 1 && a[j] > a[j + 1]) || (luachon == 2 && a[j] < a[j + 1])) {
                nhapNhayHaiHinhChuNhat(trai_j, tren, phai_j, duoi, a[j],
                    trai_j1, tren, phai_j1, duoi, a[j + 1]);

                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                setfillstyle(SOLID_FILL, BLACK);
                bar(trai_j, tren, phai_j, duoi);
                sprintf_s(giatri, sizeof(giatri), "%d", a[j]);
                giatri_x = trai_j + (phai_j - trai_j) / 2 - 5;
                giatri_y = tren + (duoi - tren) / 2.5;
                outtextxy(giatri_x, giatri_y, giatri);
                rectangle(trai_j, tren, phai_j, duoi);

                setfillstyle(SOLID_FILL, BLACK);
                bar(trai_j1, tren, phai_j1, duoi);
                sprintf_s(giatri, sizeof(giatri), "%d", a[j + 1]);
                giatri_x = trai_j1 + (phai_j1 - trai_j1) / 2 - 5;
                giatri_y = tren + (duoi - tren) / 2.5;
                outtextxy(giatri_x, giatri_y, giatri);
                rectangle(trai_j1, tren, phai_j1, duoi);
            }
            else {
                setfillstyle(SOLID_FILL, BLACK);
                bar(trai_j, tren, phai_j, duoi);
                sprintf_s(giatri, sizeof(giatri), "%d", a[j]);
                giatri_x = trai_j + (phai_j - trai_j) / 2 - 5;
                giatri_y = tren + (duoi - tren) / 2.5;
                outtextxy(giatri_x, giatri_y, giatri);
                rectangle(trai_j, tren, phai_j, duoi);

                setfillstyle(SOLID_FILL, BLACK);
                bar(trai_j1, tren, phai_j1, duoi);
                sprintf_s(giatri, sizeof(giatri), "%d", a[j + 1]);
                giatri_x = trai_j1 + (phai_j1 - trai_j1) / 2 - 5;
                giatri_y = tren + (duoi - tren) / 2.5;
                outtextxy(giatri_x, giatri_y, giatri);
                rectangle(trai_j1, tren, phai_j1, duoi);
            }

            delay(500);
        }

        // Làm nổi bật phần đã sắp xếp
        setfillstyle(SOLID_FILL, GREEN);
        int trai_da_sap_xep = 50 + (n - 1 - i) * 100;
        int phai_da_sap_xep = 150 + (n - 1 - i) * 100;
        bar(trai_da_sap_xep, tren, phai_da_sap_xep, duoi);
        sprintf_s(giatri, sizeof(giatri), "%d", a[n - 1 - i]);
        double giatri_x = trai_da_sap_xep + (phai_da_sap_xep - trai_da_sap_xep) / 2 - 5;
        double giatri_y = tren + (duoi - tren) / 2.5;
        outtextxy(giatri_x, giatri_y, giatri);
        rectangle(trai_da_sap_xep, tren, phai_da_sap_xep, duoi);
    }

    // Làm nổi bật phần tử đầu tiên nếu đã sắp xếp
    setfillstyle(SOLID_FILL, GREEN);
    bar(trai, tren, phai, duoi);
    sprintf_s(giatri, sizeof(giatri), "%d", a[0]);
    double giatri_x = trai + (phai - trai) / 2 - 5;
    double giatri_y = tren + (duoi - tren) / 2.5;
    outtextxy(giatri_x, giatri_y, giatri);
    rectangle(trai, tren, phai, duoi);
}

int main() {
    int luachon;
    cout << "Ban muon sap xep tang dan hay giam dan?" << endl;
    cout << "1. Tang dan" << endl;
    cout << "2. Giam dan" << endl;
    cout << "Lua chon cua ban: "; cin >> luachon;

    initwindow(1000, 500, "Chương trình");
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    char vanban[] = "Bubble Sort";
    outtextxy(375, 50, vanban);

    const int n = 8;
    int a[n] = {};
    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 50;
    }

    veMang(a, n, 50, 100, 150, 150);

    sapXepNoiBot(a, n, luachon);

    getch();
    closegraph();
    return 0;
}
