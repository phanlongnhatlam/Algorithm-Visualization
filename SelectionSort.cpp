#include "graphics.h"
#include <windows.h> 
#include <iostream>
#include <cstdlib>
#pragma comment(lib, "graphics.lib")
using namespace std;
void NhapNhay(int left1, int top1, int right1, int bottom1, int value1,int left2, int top2, int right2, int bottom2, int value2) {
    char giatri1[10], giatri2[10];
    sprintf_s(giatri1, sizeof(giatri1), "%d", value1);
    sprintf_s(giatri2, sizeof(giatri2), "%d", value2);
    double giatri_x1 = left1 + (right1 - left1) / 2 - 5;
    double giatri_y1 = top1 + (bottom1 - top1) / 2.5;
    double giatri_x2 = left2 + (right2 - left2) / 2 - 5;
    double giatri_y2 = top2 + (bottom2 - top2) / 2.5;
    /*nhấp nháy vàng -> đen : 2 lần*/
    for (int k = 0; k < 3; k++) {
        setfillstyle(SOLID_FILL, YELLOW);
        bar(left1, top1, right1, bottom1);
        outtextxy(giatri_x1, giatri_y1, giatri1);
        rectangle(left1, top1, right1, bottom1);

        bar(left2, top2, right2, bottom2);
        outtextxy(giatri_x2, giatri_y2, giatri2);
        rectangle(left2, top2, right2, bottom2);
        delay(150);

        setfillstyle(SOLID_FILL, BLACK);
        bar(left1, top1, right1, bottom1);
        outtextxy(giatri_x1, giatri_y1, giatri1);
        rectangle(left1, top1, right1, bottom1);

        bar(left2, top2, right2, bottom2);
        outtextxy(giatri_x2, giatri_y2, giatri2);
        rectangle(left2, top2, right2, bottom2);
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
    char vanban[] = "Selection Sort";
    outtextxy(375, 50, vanban);
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
    for (int i = 0; i < 8; i++) {
        // Vẽ hình chữ nhật
        rectangle(left, top, right, bottom);
        // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
        sprintf_s(giatri, "%d", a[i]);
        double giatri_x = left + (right - left) / 2 - 5;
        double giatri_y = top + (bottom - top) / 2.5;
        outtextxy(giatri_x, giatri_y, giatri);
        // Đánh số thứ tự
        sprintf_s(text,"%d", i); // Số thứ tự bắt đầu từ 0
        int text_x = left + (right - left) / 2 - 5; // Căn giữa theo trục x
        int text_y = bottom + 10; // Cách hình chữ nhật một khoảng
        outtextxy(text_x, text_y, text);
        // Di chuyển tọa độ hình chữ nhật sang phải cho hình chữ nhật tiếp theo
        left += 100;
        right += 100;
    }
    // reset lại từ đầu
    left = 50;
    right = 150;
    int text_x = 300;
    int text_y = 225;
    /*=================================*/
    char min_pos_text[50];
    char j_text[50];
    for (int i = 0; i < n - 1; i++) {
        int min_pos = i;
        sprintf_s(min_pos_text,"min_pos = %d", min_pos);
        setfillstyle(SOLID_FILL, BLACK);
        bar(text_x, text_y, text_x + 200, text_y + 20);
        outtextxy(text_x, text_y, min_pos_text);
        setfillstyle(SOLID_FILL, RED);
        bar(left, top, right, bottom);
        // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
        sprintf_s(giatri, "%d", a[i]);
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
            sprintf_s(giatri, "%d", a[j]);
            giatri_x = left + (right - left) / 2 - 5;
            giatri_y = top + (bottom - top) / 2.5;
            outtextxy(giatri_x, giatri_y, giatri);
            // Vẽ lại đường viền sau khi đổ màu
            rectangle(left, top, right, bottom);
            // Cập nhật lại j
            sprintf_s(j_text,"j = %d", j);
            setfillstyle(SOLID_FILL, BLACK);
            bar(text_x, text_y + 20, text_x + 200, text_y + 40);
            outtextxy(text_x, text_y + 20, j_text);
            // Đợi một khoảng thời gian ngắn
            delay(500);
            // Đổ màu nền đen
            setfillstyle(SOLID_FILL, BLACK);
            bar(left, top, right, bottom);
            // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
            sprintf_s(giatri, "%d", a[j]);
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
                    sprintf_s(min_pos_text, "min_pos = %d", min_pos);
                    setfillstyle(SOLID_FILL, BLACK);
                    bar(text_x, text_y, text_x + 200, text_y + 20);
                    outtextxy(text_x, text_y, min_pos_text);
                    /*===============================*/
                }
            }
            else {
                if (a[j] > a[min_pos]) {
                    min_pos = j;
                    sprintf_s(min_pos_text,"min_pos = %d", min_pos);
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
        // nhấp nháy trước khi swap 2 phần tử cho nhau :v
        int left_i = 50 + (i) * 100;
        int right_i = 150 + (i) * 100;
        int left_min = 50 + (min_pos) * 100;
        int right_min = 150 + (min_pos) * 100;
        NhapNhay(left_i, top, right_i, bottom, a[i], left_min, top, right_min, bottom, a[min_pos]);
        // Swap giá trị
        swap(a[i], a[min_pos]); 
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
        /*
            for (i<n-1)
                for(j<n)
            i==n-2 là phần tử kế cuối
            (i+1) là phần tử cuối cùng :V
        */
        if (i == n - 2 ) {
            left = 50 + (i + 1) * 100;
            right = 150 + (i + 1) * 100;
            // Nhấp nháy 3 lần phần tử cuối cùng
            for (int k = 1; k <= 3; k++) {
                setfillstyle(SOLID_FILL, GREEN);
                bar(left, top, right, bottom);
                /*nhấp nháy*/
                sprintf_s(giatri, sizeof(giatri), "%d", a[i + 1]);
                giatri_x = left + (right - left) / 2 - 5;
                giatri_y = top + (bottom - top) / 2.5;
                outtextxy(giatri_x, giatri_y, giatri);
                rectangle(left, top, right, bottom);
                delay(150);
                setfillstyle(SOLID_FILL, BLACK);
                bar(left, top, right, bottom);
                /*nhấp nháy*/
                sprintf_s(giatri, sizeof(giatri), "%d", a[i + 1]);
                giatri_x = left + (right - left) / 2 - 5;
                giatri_y = top + (bottom - top) / 2.5;
                outtextxy(giatri_x, giatri_y, giatri);
                rectangle(left, top, right, bottom);
                delay(150);
                setfillstyle(SOLID_FILL, GREEN);
                bar(left, top, right, bottom);
                /*nhấp nháy*/
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
