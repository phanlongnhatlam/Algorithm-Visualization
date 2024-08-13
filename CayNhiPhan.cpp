#include "graphics.h"
#include <iostream>
#include <queue>
#include <windows.h>
#pragma comment(lib, "graphics.lib")

using namespace std;

// Cấu trúc của một nút trong cây nhị phân
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Hàm tạo nút mới
Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Loi cap phat bo nho!" << endl;
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Hàm thêm nút vào cây nhị phân
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data == root->data) {
        cout << "Gia tri da ton tai trong cay. Khong the chen." << endl;
        return root;
    }
    else if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Hàm tìm giá trị nhỏ nhất của cây
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Hàm xóa một nút khỏi cây nhị phân
Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        cout << "Gia tri khong ton tai trong cay. Khong the xoa." << endl;
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Hàm vẽ một nút cây nhị phân
void veNode(int x, int y, int data) {
    char data_txt[10];
    sprintf_s(data_txt, "%d", data);
    circle(x, y, 20);
    outtextxy(x - 10, y - 10, data_txt);
}

// Hàm vẽ cạnh của cây nhị phân
void veCanh(int x1, int y1, int x2, int y2) {
    line(x1, y1, x2, y2);
}

// Hàm vẽ cây nhị phân
void veCay(Node* root, int x, int y, int khoangCachX, int khoangCachY) {
    if (root != NULL) {
        veNode(x, y, root->data);
        if (root->left != NULL) {
            veCanh(x, y + 20, x - khoangCachX + 20, y + khoangCachY - 20);
            veCay(root->left, x - khoangCachX, y + khoangCachY, khoangCachX / 2, khoangCachY);
        }
        if (root->right != NULL) {
            veCanh(x, y + 20, x + khoangCachX - 20, y + khoangCachY - 20);
            veCay(root->right, x + khoangCachX, y + khoangCachY, khoangCachX / 2, khoangCachY);
        }
    }
}

int main() {
    initwindow(1000, 600, "Cay Nhi Phan Visualization");

    Node* root = NULL;

    int choice, value;

    do {
        cout << "Lua chon: 1. Them Node | 2. Xoa Node | 0. Thoat: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Nhap gia tri Node: ";
            cin >> value;
            root = insertNode(root, value);
            cleardevice();  // Xóa màn hình để vẽ lại cây
            veCay(root, 500, 50, 200, 80);  // Vẽ cây với tọa độ gốc ban đầu
            break;
        case 2:
            cout << "Nhap gia tri can xoa: ";
            cin >> value;
            root = deleteNode(root, value);
            cleardevice();  // Xóa màn hình để vẽ lại cây
            veCay(root, 500, 50, 200, 80);  // Vẽ lại cây sau khi xóa
            break;
        case 0:
            cout << "Thoat chuong trinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
            break;
        }

        delay(500);  // Có thể loại bỏ nếu không cần thiết

    } while (choice != 0);

    closegraph();
    return 0;
}
