#include "graphics.h"
#include <windows.h> 
#include <iostream>
#include <cstdlib>
#pragma comment(lib, "graphics.lib")
using namespace std;

void blinkRectangle(int left, int top, int right, int bottom, int value) {
    char giatri[10];
    sprintf_s(giatri, sizeof(giatri), "%d", value);
    double giatri_x = left + (right - left) / 2 - 5;
    double giatri_y = top + (bottom - top) / 2.5;

    for (int k = 0; k < 3; k++) {
        setfillstyle(SOLID_FILL, YELLOW);
        bar(left, top, right, bottom);
        outtextxy(giatri_x, giatri_y, giatri);
        rectangle(left, top, right, bottom);
        delay(150);
        setfillstyle(SOLID_FILL, BLACK);
        bar(left, top, right, bottom);
        outtextxy(giatri_x, giatri_y, giatri);
        rectangle(left, top, right, bottom);
        delay(150);
    }
}

int main() {
    int luachon;
    cout << "Ban muon sap xep tang dan hay giam dan ?" << endl;
    cout << "1. Tang dan" << endl;
    cout << "2. Giam dan" << endl;
    cout << "Lua chon cua ban : "; cin >> luachon;
    initwindow(1000, 500, "chuong trinh");
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    // Chuỗi cần vẽ lên cửa sổ đồ họa
    char vanban[] = "Selection Sort";
    // Vẽ chuỗi "SelectionSort" tại tọa độ (375, 50)
    outtextxy(375, 50, vanban);
    // random giá trị cho mảng
    const int n = 8;
    int a[n] = {};
    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 50;
    }
    int left = 50, top = 100;
    int right = 150, bottom = 150;
    char giatri[10];
    char text[10];
    // Vẽ các hình chữ nhật và đánh số thứ tự
    for (int i = 0; i < 8; i++) {
        // Vẽ hình chữ nhật
        rectangle(left, top, right, bottom);
        // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
        sprintf_s(giatri, sizeof(giatri), "%d", a[i]);
        double giatri_x = left + (right - left) / 2 - 5;
        double giatri_y = top + (bottom - top) / 2.5;
        outtextxy(giatri_x, giatri_y, giatri);
        // Đánh số thứ tự
        sprintf_s(text, sizeof(text), "%d", i); // Số thứ tự bắt đầu từ 0
        int text_x = left + (right - left) / 2 - 5; // Căn giữa theo trục x
        int text_y = bottom + 10; // Cách hình chữ nhật một khoảng
        outtextxy(text_x, text_y, text);
        // Di chuyển tọa độ hình chữ nhật sang phải cho hình chữ nhật tiếp theo
        left += 100;
        right += 100;
    }
    // reset
    left = 50;
    right = 150;
    int text_x = 300;
    int text_y = 225;

    /*=================================*/
    char min_pos_text[50];
    char j_text[50];
    for (int i = 0; i < n - 1; i++) {
        int min_pos = i;
        sprintf_s(min_pos_text, sizeof(min_pos_text), "min_pos = %d", min_pos);
        setfillstyle(SOLID_FILL, BLACK);
        bar(text_x, text_y, text_x + 200, text_y + 20);
        outtextxy(text_x, text_y, min_pos_text);

        setfillstyle(SOLID_FILL, RED);
        bar(left, top, right, bottom);
        // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
        sprintf_s(giatri, sizeof(giatri), "%d", a[i]);
        double giatri_x = left + (right - left) / 2 - 5;
        double giatri_y = top + (bottom - top) / 2.5;
        outtextxy(giatri_x, giatri_y, giatri);
        rectangle(left, top, right, bottom);
        delay(500);
        left += 100;
        right += 100;
        // Đổ màu vàng và trở lại màu đen cho từng ô
        for (int j = i + 1; j < n; j++) {
            // Đổ màu nền vàng
            setfillstyle(SOLID_FILL, YELLOW);
            bar(left, top, right, bottom);
            // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
            sprintf_s(giatri, sizeof(giatri), "%d", a[j]);
            giatri_x = left + (right - left) / 2 - 5;
            giatri_y = top + (bottom - top) / 2.5;
            outtextxy(giatri_x, giatri_y, giatri);
            // Vẽ lại đường viền sau khi đổ màu
            rectangle(left, top, right, bottom);

            // Cập nhật lại j
            sprintf_s(j_text, sizeof(j_text), "j = %d", j);
            setfillstyle(SOLID_FILL, BLACK);
            bar(text_x, text_y + 20, text_x + 200, text_y + 40);
            outtextxy(text_x, text_y + 20, j_text);

            // Đợi một khoảng thời gian ngắn
            delay(500);
            // Đổ màu nền đen
            setfillstyle(SOLID_FILL, BLACK);
            bar(left, top, right, bottom);
            // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
            sprintf_s(giatri, sizeof(giatri), "%d", a[j]);
            giatri_x = left + (right - left) / 2 - 5;
            giatri_y = top + (bottom - top) / 2.5;
            outtextxy(giatri_x, giatri_y, giatri);
            // Vẽ lại đường viền sau khi đổ màu
            rectangle(left, top, right, bottom);

            /*===============================*/
            /*Selection Sort*/
            if (luachon == 1) {
                if (a[j] < a[min_pos]) {
                    min_pos = j;
                    sprintf_s(min_pos_text, sizeof(min_pos_text), "min_pos = %d", min_pos);
                    setfillstyle(SOLID_FILL, BLACK);
                    bar(text_x, text_y, text_x + 200, text_y + 20);
                    outtextxy(text_x, text_y, min_pos_text);
                    /*===============================*/
                }
            }
            else {
                if (a[j] > a[min_pos]) {
                    min_pos = j;
                    sprintf_s(min_pos_text, sizeof(min_pos_text), "min_pos = %d", min_pos);
                    setfillstyle(SOLID_FILL, BLACK);
                    bar(text_x, text_y, text_x + 200, text_y + 20);
                    outtextxy(text_x, text_y, min_pos_text);
                    /*===============================*/
                }
            }
            /*===============================*/
            // Di chuyển tọa độ hình chữ nhật sang phải cho hình chữ nhật tiếp theo
            left += 100;
            right += 100;
        }

        // Blink before swapping
        int left_i = 50 + (i) * 100;
        int right_i = 150 + (i) * 100;
        int left_min = 50 + (min_pos) * 100;
        int right_min = 150 + (min_pos) * 100;

        blinkRectangle(left_i, top, right_i, bottom, a[i]);
        blinkRectangle(left_min, top, right_min, bottom, a[min_pos]);

        // Swap values
        int temp = a[min_pos];
        a[min_pos] = a[i];
        a[i] = temp;

        // VẼ LẠI CÁC PHẦN TỬ ĐÃ SẮP XẾP
        left = 50 + (i) * 100;
        right = 150 + (i) * 100;
        setfillstyle(SOLID_FILL, GREEN);
        bar(left, top, right, bottom);
        sprintf_s(giatri, sizeof(giatri), "%d", a[i]);
        giatri_x = left + (right - left) / 2 - 5;
        giatri_y = top + (bottom - top) / 2.5;
        outtextxy(giatri_x, giatri_y, giatri);
        rectangle(left, top, right, bottom);
        if (a[i] != a[min_pos]) {
            left = 50 + 100 * min_pos;
            right = 150 + 100 * min_pos;
            setfillstyle(SOLID_FILL, BLACK);
            bar(left, top, right, bottom);
            sprintf_s(giatri, sizeof(giatri), "%d", a[min_pos]);
            giatri_x = left + (right - left) / 2 - 5;
            giatri_y = top + (bottom - top) / 2.5;
            outtextxy(giatri_x, giatri_y, giatri);
            rectangle(left, top, right, bottom);
        }
        left = 50 + (i + 1) * 100;
        right = 150 + (i + 1) * 100;
        // Phần tử cuối cùng
        if (i == n - 2) {
            left = 50 + (i + 1) * 100;
            right = 150 + (i + 1) * 100;
            // Nhấp nháy 3 lần phần tử cuối cùng
            for (int k = 1; k <= 3; k++) {
                setfillstyle(SOLID_FILL, GREEN);
                bar(left, top, right, bottom);
                // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
                sprintf_s(giatri, sizeof(giatri), "%d", a[i + 1]);
                giatri_x = left + (right - left) / 2 - 5;
                giatri_y = top + (bottom - top) / 2.5;
                outtextxy(giatri_x, giatri_y, giatri);
                rectangle(left, top, right, bottom);
                delay(150);
                setfillstyle(SOLID_FILL, BLACK);
                bar(left, top, right, bottom);
                // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
                sprintf_s(giatri, sizeof(giatri), "%d", a[i + 1]);
                giatri_x = left + (right - left) / 2 - 5;
                giatri_y = top + (bottom - top) / 2.5;
                outtextxy(giatri_x, giatri_y, giatri);
                rectangle(left, top, right, bottom);
                delay(150);
                setfillstyle(SOLID_FILL, GREEN);
                bar(left, top, right, bottom);
                // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
                sprintf_s(giatri, sizeof(giatri), "%d", a[i + 1]);
                giatri_x = left + (right - left) / 2 - 5;
                giatri_y = top + (bottom - top) / 2.5;
                outtextxy(giatri_x, giatri_y, giatri);
                rectangle(left, top, right, bottom);
                delay(150);
            }
        }
    }
    getch();
    closegraph();
    return 0;
}
