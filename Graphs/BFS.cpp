#include "graphics.h"
#include <iostream>
#pragma comment(lib, "graphics.lib")
using namespace std;
struct ArrQueue {
    int front, rear;
    int capacity;
    int* Q;
    ArrQueue(int cap = 100) {
        Q = new int[cap];
        capacity = cap;
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear - front == -1) || (rear - front == capacity - 1);
    }

    void EnQueue(int x) {
        if (!isFull()) {
            if (isEmpty()) {
                front = 0;
            }
            if (rear == capacity - 1) {
                rear = -1;
            }
            Q[++rear] = x;
        }
        else {
            cout << "Hang doi da day !!!" << endl;
        }
    }
    int DeQueue() {
        int x = Q[front];
        if (rear == front) {
            rear = front = -1;
        }
        else {
            front++;
            if (front >= capacity) {
                front = 0;
            }
        }
        return x;
    }
};
const int MAX_NODES = 8;
char bfsResult[MAX_NODES];
int resultIndex = 0;
int graph[MAX_NODES][MAX_NODES] = {
    {0, 1, 1, 0, 0, 0, 0, 0},  // A
    {1, 0, 0, 1, 1, 0, 0, 0},  // B
    {1, 0, 0, 0, 0, 1, 1, 0},  // C
    {0, 1, 0, 0, 0, 0, 0, 1},  // D
    {0, 1, 0, 0, 0, 0, 0, 1},  // E
    {0, 0, 1, 0, 0, 0, 0, 1},  // F
    {0, 0, 1, 0, 0, 0, 0, 1},  // G
    {0, 0, 0, 1, 1, 1, 1, 0}   // H
};
bool visited[MAX_NODES] = { false };
int x[MAX_NODES] = { 200, 100, 300, 50, 150, 250, 350, 200 };
int y[MAX_NODES] = { 50, 150, 150, 250, 250, 250, 250, 350 };
int charToIndex(char c) {
    return c - 'A';
}
// Hàm vẽ đỉnh 
void drawNode(int index, int borderColor, int fillColor) {
    setcolor(borderColor);
    circle(x[index], y[index], 20);
    setfillstyle(SOLID_FILL, fillColor);
    floodfill(x[index], y[index], borderColor);
    char label[2];
    sprintf_s(label, "%c", 'A' + index);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    setbkcolor(fillColor);  // Đặt màu nền của chữ giống màu lấp đầy của node
    setcolor(BLACK);  // Màu chữ là màu đen để tương phản
    outtextxy(x[index] - 10, y[index] - 10, label);  // Điều chỉnh vị trí nhãn 
}
// hàm vẽ các đường thẳng
void drawEdge(int u, int v) {
    setcolor(WHITE);
    line(x[u], y[u], x[v], y[v]);
}
// hàm vẽ hàng đợi
void drawQueue(ArrQueue& nodeQueue) {
    int queueX = 450;   // Tọa độ X bắt đầu của hàng đợi
    int queueY = 350;   // Tọa độ Y bắt đầu của hàng đợi 
    int boxSize = 30;   // Kích thước mỗi ô trong hàng đợi
    // Xóa vùng hiển thị hàng đợi trước khi vẽ
    setfillstyle(SOLID_FILL, BLACK);  // Nền đen
    bar(queueX - 1, queueY - (MAX_NODES * boxSize) - 1, queueX + boxSize + 1, queueY + 1);
    // Duyệt qua các phần tử trong hàng đợi
    int index = 0;
    int i = nodeQueue.front;
    // rear + 1 : các phần tử có trong hàng đợi
    while (i != nodeQueue.rear + 1) {
        // Vẽ hình chữ nhật đại diện cho phần tử trong hàng đợi
        setcolor(WHITE);  // Viền trắng
        rectangle(queueX, queueY - (index + 1) * boxSize, queueX + boxSize, queueY - index * boxSize);
        // Hiển thị ký tự của đỉnh trong hàng đợi
        char label[2];
        sprintf_s(label, "%c", 'A' + nodeQueue.Q[i]);  // Biến đổi số thành ký tự (A, B, C, ...)
        setbkcolor(BLACK);  // Nền chữ màu đen
        setcolor(WHITE);  // Màu chữ là màu trắng
        outtextxy(queueX + 10, queueY - (index + 1) * boxSize + 5, label);  // Căn giữa chữ trong ô
        index++;
        i = (i + 1) % nodeQueue.capacity;  // Di chuyển tới phần tử tiếp theo
    }
}
void BFS(int startNode) {
    ArrQueue nodeQueue(MAX_NODES);
    nodeQueue.EnQueue(startNode);
    visited[startNode] = true;
    while (!nodeQueue.isEmpty()) {
        int node = nodeQueue.DeQueue();
        bfsResult[resultIndex++] = 'A' + node; // ví dụ A+3 thì ra D tại vì lưu vô mảng char <;

        // đi từng node, node nào thăm rồi thì đánh dấu màu vàng, còn không thì vẫn là màu xám
        for (int i = 0; i < MAX_NODES; i++) {
            if (visited[i]) {
                drawNode(i, YELLOW, YELLOW);
            }
        }
        // vẽ node đã thăm
        drawNode(node, YELLOW, YELLOW);
        // vẽ hàng đợi
        drawQueue(nodeQueue);
        delay(1500);
        // kiểm tra đỉnh nào chưa thăm, và đánh dấu nó rồi enqueue
        for (int i = 0; i < MAX_NODES; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = true;
                nodeQueue.EnQueue(i);
            }
        }
        drawQueue(nodeQueue);
        delay(1500);
    }
}
int main() {
    initwindow(600, 400, "Minh Hoa BFS");
    // vẽ các node
    for (int i = 0; i < MAX_NODES; i++) {
        drawNode(i, LIGHTGRAY, LIGHTGRAY);
    }
    // hàm này dùng để vẽ cạnh nối (trong ma trận kề nếu giá trị là 0 thì không vẽ :v)
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = i + 1; j < MAX_NODES; j++) {
            if (graph[i][j]) {
                drawEdge(i, j);
            }
        }
    }
    cout << "Nhap dinh bat dau BFS (A-H): ";
    char startNode;
    cin >> startNode;
    BFS(charToIndex(startNode));
    cout << "Ket qua duyet BFS: ";
    for (int i = 0; i < resultIndex; i++) {
        cout << bfsResult[i] << " ";
    }
    cout << endl;
    system("pause");
    closegraph();
    return 0;
}
