#include "graphics.h"
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#pragma comment(lib, "graphics.lib")
using namespace std;

const int TABLE_SIZE = 5;  // Kích thước bảng băm
const int BOX_WIDTH = 100;
const int BOX_HEIGHT = 100;
const int START_X = 50;
const int START_Y = 100;
const int SPACING = 150;
const int LINKED_LIST_WIDTH = 100;
const int LINKED_LIST_HEIGHT = 30;
const int LIST_START_X = START_X;
const int LIST_START_Y = START_Y + BOX_HEIGHT + 50;

// Cấu trúc một node trong danh sách liên kết đơn
struct Node {
    int data;
    Node* next;
};

// Hàm băm
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Hàm vẽ bảng băm
void veBangBam(Node* table[]) {
    setcolor(WHITE);
    for (int i = 0; i < TABLE_SIZE; i++) {
        rectangle(START_X + i * SPACING, START_Y, START_X + i * SPACING + BOX_WIDTH, START_Y + BOX_HEIGHT);
        char index[10];
        sprintf_s(index, sizeof(index), "%d", i);
        outtextxy(START_X + i * SPACING + BOX_WIDTH / 2 - 10, START_Y + 10, index);

        // Vẽ danh sách liên kết ở từng vị trí trong bảng băm
        Node* temp = table[i];
        int yOffset = 0;
        while (temp != nullptr) {
            rectangle(START_X + i * SPACING, LIST_START_Y + yOffset, START_X + i * SPACING + LINKED_LIST_WIDTH, LIST_START_Y + yOffset + LINKED_LIST_HEIGHT);
            char value[10];
            sprintf_s(value, sizeof(value), "%d", temp->data);
            outtextxy(START_X + i * SPACING + LINKED_LIST_WIDTH / 2 - 10, LIST_START_Y + yOffset + LINKED_LIST_HEIGHT / 2 - 10, value);
            yOffset += LINKED_LIST_HEIGHT;
            temp = temp->next;
        }
    }
}

// Hàm để thêm phần tử vào bảng băm
void themPhanTu(Node* table[], int key) {
    int index = hashFunction(key);

    // Hiển thị giá trị key và hash
    char msg[50];
    sprintf_s(msg, sizeof(msg), "Key: %d, Hash: %d", key, index);
    outtextxy(START_X, START_Y - 50, msg);
    delay(1000);

    // Thêm phần tử vào danh sách liên kết tương ứng
    Node* newNode = new Node();
    newNode->data = key;
    newNode->next = table[index];
    table[index] = newNode;

    cleardevice(); // Xóa màn hình
    veBangBam(table); // Vẽ lại bảng băm với phần tử mới
    delay(1000);
}

// Hàm xóa phần tử khỏi bảng băm
void xoaPhanTu(Node* table[], int key) {
    int index = hashFunction(key);
    Node* temp = table[index];
    Node* prev = nullptr;

    while (temp != nullptr) {
        if (temp->data == key) {
            if (prev == nullptr) {
                table[index] = temp->next;
            }
            else {
                prev->next = temp->next;
            }
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    cleardevice(); // Xóa màn hình
    veBangBam(table); // Vẽ lại bảng băm sau khi xóa
    delay(1000);
}

// Hàm để nhận đầu vào từ người dùng
int nhapSo() {
    int key;
    cout << "Nhap so (hoac -1 de thoat): ";
    cin >> key;
    return key;
}

int main() {
    initwindow(1800, 1200, "Bảng Băm");
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);

    Node* table[TABLE_SIZE] = { nullptr }; // Khởi tạo bảng băm với các danh sách liên kết trống

    veBangBam(table);

    int luaChon;
    while (true) {
        cout << "Chon thao tac:\n1. Them phan tu\n2. Xoa phan tu\n3. Thoat\n";
        cin >> luaChon;

        if (luaChon == 1) {
            int key = nhapSo();
            if (key == -1) break;
            themPhanTu(table, key);
        }
        else if (luaChon == 2) {
            int key = nhapSo();
            if (key == -1) break;
            xoaPhanTu(table, key);
        }
        else if (luaChon == 3) {
            break;
        }
        else {
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    }
    closegraph();
    return 0;
}
