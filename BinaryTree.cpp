#include "graphics.h"
#include <iostream>
#include <windows.h>
#pragma comment(lib, "graphics.lib")
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
// Hàm tạo nút mới
Node* createNode(int data) {
    Node* newNode = new Node();
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
        cout << "Khong the chen gia tri nay !!!" << endl;
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
// Hàm tìm và thay thế giá trị nút bị xóa bằng nút trái nhất của cây con phải
void searchLeftMostNode(Node*& deletedNode, Node*& replacedNode) {
    if (replacedNode->left != NULL) {
        searchLeftMostNode(deletedNode, replacedNode->left);
    }
    else {
        deletedNode->data = replacedNode->data;
        deletedNode = replacedNode;
        replacedNode = replacedNode->right;
    }
}
// Hàm xóa một nút khỏi cây nhị phân bằng đệ quy
void deleteNodeRecursive(Node*& root, int data) {
    if (root == NULL) {
        cout << "Cay nhi phan rong !!! " << endl;
        return;
    }
    // tìm bên trái
    if (data < root->data) {
        deleteNodeRecursive(root->left, data);
    }
    // tìm bên phải
    else if (data > root->data) {
        deleteNodeRecursive(root->right, data);
    }
    else {
        Node* deletedNode = root;
        if (root->left == NULL) {
            root = root->right;
        }
        else if (root->right == NULL) {
            root = root->left;
        }
        else {
            searchLeftMostNode(deletedNode, root->right);
        }
        delete deletedNode;
    }
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
            veCay(root->left, x - khoangCachX, y + khoangCachY, khoangCachX / 2, khoangCachY); // sử dụng đệ quy, mỗi lần đệ quy thì khoảng cách bị /2 
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
        system("cls");
        cout << "=============MENU============" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "1. Insert node" << endl;
        cout << "2. Delete node" << endl;
        cout << "=============================" << endl;
        cout << "Lua chon cua ban: ";
        cin >> choice;
        switch (choice) {
        case 1:
            system("cls");
            cout << "Nhap gia tri Node: ";
            cin >> value;
            root = insertNode(root, value);
            cleardevice();  // Xóa màn hình để vẽ lại cây
            veCay(root, 500, 50, 200, 80);  // Vẽ cây
            break;
        case 2:
            system("cls");
            cout << "Nhap gia tri can xoa: ";
            cin >> value;
            deleteNodeRecursive(root, value);
            cleardevice();  // Xóa màn hình để vẽ lại cây
            veCay(root, 500, 50, 200, 80);  // Vẽ lại cây 
            break;
        case 0:
            system("cls");
            cout << "Thoat chuong trinh." << endl;
            break;
        default:
            system("cls");
            cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
            break;
        }
        delay(500);
    } while (choice != 0);
    system("pause");
    closegraph();
    return 0;
}
