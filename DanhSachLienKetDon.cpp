#include "graphics.h"
#include <windows.h>
#include <iostream>
#include<cmath>
#pragma comment(lib, "graphics.lib")
using namespace std;
#define M_PI 3.14159265358979323846
struct Node {
    int data;
    Node* next;
};
// Hàm vẽ một node
void veNode(int x, int y, int giatri) {
    char giatri_txt[10];
    sprintf_s(giatri_txt, "%d", giatri);
    rectangle(x, y, x + 50, y + 30); // Vẽ hình chữ nhật cho node
    outtextxy(x + 15, y + 5, giatri_txt); // Vẽ giá trị bên trong node
}
// Hàm vẽ mũi tên nối các node theo đường chéo với đầu mũi tên đẹp hơn
void veMuiTen(int x1, int y1, int x2, int y2) {
    // Vẽ đường thẳng chính của mũi tên
    line(x1, y1, x2, y2);
    // Tính toán độ dài và góc của mũi tên
    int dx = x2 - x1;
    int dy = y2 - y1;
    float angle = atan2(dy, dx); // Góc của mũi tên
    // Độ dài của cánh mũi tên
    int arrowLength = 10;
    // Góc của cánh mũi tên so với thân mũi tên
    float arrowAngle = M_PI / 6; // 30 độ
    // Tính toán tọa độ của hai cánh mũi tên
    int xLeft = x2 - arrowLength * cos(angle + arrowAngle);
    int yLeft = y2 - arrowLength * sin(angle + arrowAngle);
    int xRight = x2 - arrowLength * cos(angle - arrowAngle);
    int yRight = y2 - arrowLength * sin(angle - arrowAngle);
    // Vẽ hai cánh mũi tên
    line(x2, y2, xLeft, yLeft);
    line(x2, y2, xRight, yRight);
}
// Hàm vẽ toàn bộ danh sách liên kết theo đường chéo từ trên trái xuống dưới phải
void veDanhSachLienKet(Node* head, int x, int y) {
    Node* temp = head;
    while (temp != nullptr) {
        veNode(x, y, temp->data);
        if (temp->next != nullptr) {
            veMuiTen(x + 50, y + 15, x + 100, y + 65); // Mũi tên chéo nối node hiện tại với node tiếp theo
        }
        temp = temp->next;
        x += 100; // Di chuyển vị trí x cho node tiếp theo
        y += 50;  // Di chuyển vị trí y cho node tiếp theo
    }
}
// Hàm đếm các phần tử có trong danh sách liên kết 
int Dem(Node* head)
{
    int dem = 0;
    while (head != NULL)
    {
        head = head->next;
        dem++;
    }
    return dem;
}
// Hàm thêm phần tử vào đầu danh sách liên kết
void insertHead(Node*& head, int giatri, int x, int y) {
    Node* newNode = new Node();
    newNode->data = giatri;
    newNode->next = head;
    head = newNode;
    cleardevice();  // Xóa màn hình
    veDanhSachLienKet(head, x, y);
}

// Hàm thêm phần tử vào cuối danh sách liên kết
void insertTail(Node*& head, int giatri, int x, int y) {
    Node* newNode = new Node();
    newNode->data = giatri;
    newNode->next = nullptr;
    // nếu mà head rỗng 
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cleardevice();  // Xóa màn hình
    veDanhSachLienKet(head, x, y);
}
// Hàm thêm phần tử vào giữa danh sách liên kết
void insertMiddle(Node*& head, int giatri, int pos, int x, int y) {
    if (pos < 0 || pos > Dem(head)) {
        cout << "Vi tri chen khong hop le !!! " << endl;
        return;
    }
    if (pos == 0) {
        insertHead(head,giatri,x,y);
    }
    else
    {
        Node* Find = head;
        // chạy đến trước vị trí cần chèn 
        for (int i = 0; i < pos - 1; i++) {
            Find = Find->next;
        }
        Node* tmp = new Node();
        tmp->data = giatri;
        tmp->next = Find->next;
        Find->next = tmp;
    }
    cleardevice();  // Xóa màn hình
    veDanhSachLienKet(head, x, y);
}
// Hàm xóa phần tử ở đầu danh sách liên kết
void deleteHead(Node*& head, int x, int y) {
    if (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cleardevice();  // Xóa màn hình
        veDanhSachLienKet(head, x, y);
    }
    else {
        outtextxy(200, 50, (char*)"Danh sach rong, khong the xoa!");
    }
}
// Hàm xóa phần tử ở cuối danh sách liên kết
void deleteTail(Node*& head, int x, int y) {
    if (head == nullptr) {
        outtextxy(200, 50, (char*)"Danh sach rong, khong the xoa!");
        return;
    }
    Node* truoc = 0;
    Node* sau = head;
    while (sau->next != nullptr) {
        truoc = sau;
        sau = sau->next;
    }
    // nếu chỉ có một phần tử
    if (truoc == 0) {
        Node* tmp = sau;
        head = nullptr;
        delete tmp;
    }
    else
    {
        Node* tmp = sau;
        truoc->next = nullptr;
        delete tmp;
    }
    cleardevice();  // Xóa màn hình
    veDanhSachLienKet(head, x, y);
}
// Hàm xóa phần tử ở giữa danh sách liên kết
void deleteMiddle(Node*& head, int pos, int x, int y) {
    if (head == nullptr) {
        outtextxy(200, 50, (char*)"Danh sach rong, khong the xoa!");
        return;
    }
    if (pos == 0) {
        deleteHead(head, x, y);
        return;
    }
    else
    {
        Node* run = head;
        // nếu trong danh sách chỉ có một node
        if (run->next == NULL) {
            Node* tmp = run;
            head = NULL;
            delete tmp;
        }
        else
        {
            for (int i = 0; i < pos - 1; i++) {
                run = run->next;
            }
            Node* tmp = run->next;
            run->next = run->next->next;
            delete tmp;
        }
    }
    cleardevice();  // Xóa màn hình
    veDanhSachLienKet(head, x, y);
}

int main() {
    initwindow(800, 600, "Linked List Visualization");
    Node* head = nullptr;
    int x = 5, y = 5; // Bắt đầu từ góc trái trên cùng màn hình
    int choice;
    int value, pos;
    do {
        system("cls");
        cout << "=============MENU============" << endl;
        cout << "0.Thoat chuong trinh" << endl;
        cout << "1.Insert head" << endl;
        cout << "2.Insert tail" << endl;
        cout << "3.Insert middle" << endl;
        cout << "4.Delete head" << endl;
        cout << "5.Delete tail" << endl;
        cout << "6.Delete middle" << endl;
        cout << "=============================" << endl;
        cout << "Lua chon cua ban : ";
        cin >> choice;
        switch (choice) {
        case 1:
            system("cls");
            cout << "Nhap gia tri can insert vao dau: ";
            cin >> value;
            insertHead(head, value, x, y);
            break;
        case 2:
            system("cls");
            cout << "Nhap gia tri can insert vao cuoi: ";
            cin >> value;
            insertTail(head, value, x, y);
            break;
        case 3:
            system("cls");
            cout << "Nhap gia tri can insert vao giua: ";
            cin >> value;
            cout << "Nhap vi tri: ";
            cin >> pos;
            insertMiddle(head, value, pos, x, y);
            break;
        case 4:
            system("cls");
            deleteHead(head, x, y);
            break;
        case 5:
            system("cls");
            deleteTail(head, x, y);
            break;
        case 6:
            system("cls");
            cout << "Nhap vi tri can xoa: ";
            cin >> pos;
            deleteMiddle(head, pos, x, y);
            break;
        case 0:
            system("cls");
            cout << "Thoat chuong trinh." << endl;
            break;
        default:
            system("cls");
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
            break;
        }
        delay(300);  
    } while (choice != 0);
    system("pause");
    closegraph();
    return 0;
}
