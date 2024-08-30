#include "graphics.h"
#include <iostream>
#include <stack>

using namespace std;

const int MAX_NODES = 8;
char dfsResult[MAX_NODES];
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
int dfsIndex = 0;           // To track the current index in the dfsResult array
stack<int> nodeStack;

int x[MAX_NODES] = { 200, 100, 300, 50, 150, 250, 350, 200 };
int y[MAX_NODES] = { 50, 150, 150, 250, 250, 250, 250, 350 };

// Chuyển đổi đỉnh từ ký tự sang số
int charToIndex(char c) {
    return c - 'A';
}

// Hàm vẽ đỉnh
void drawNode(int index, int color) {
    setcolor(color);
    circle(x[index], y[index], 20);
    floodfill(x[index], y[index], color);

    char label[2];
    sprintf_s(label, "%c", 'A' + index);
    setcolor(WHITE);
    outtextxy(x[index] - 5, y[index] - 5, label);
}

// Hàm vẽ cạnh
void drawEdge(int u, int v) {
    setcolor(WHITE);
    line(x[u], y[u], x[v], y[v]);
}

// Hàm vẽ stack
void drawStack() {
    int stackX = 450;   // Tọa độ X bắt đầu của stack
    int stackY = 50;    // Tọa độ Y bắt đầu của stack
    int boxSize = 30;   // Kích thước mỗi ô trong stack

    // Clear the stack area before drawing
    setfillstyle(SOLID_FILL, BLACK);
    bar(stackX - 1, stackY - 1, stackX + boxSize + 1, stackY + (MAX_NODES * boxSize) + 1);

    // Sao chép stack gốc vào một stack tạm thời để duyệt
    stack<int> tempStack = nodeStack;

    // Vẽ các phần tử trong stack từ trên xuống
    int index = 0;  // Chỉ số để vẽ từng ô stack
    while (!tempStack.empty()) {
        int node = tempStack.top();  // Lấy phần tử trên cùng của stack
        tempStack.pop();             // Xóa phần tử trên cùng khỏi stack tạm

        // Vẽ hình chữ nhật đại diện cho phần tử trong stack
        setcolor(WHITE);
        rectangle(stackX, stackY + index * boxSize, stackX + boxSize, stackY + (index + 1) * boxSize);

        // Hiển thị ký tự của đỉnh trong stack
        char label[2];
        sprintf_s(label, "%c", 'A' + node);  // Biến đổi số thành ký tự (A, B, C, ...)
        setcolor(WHITE);
        outtextxy(stackX + 10, stackY + index * boxSize + 5, label);

        index++;  // Di chuyển xuống để vẽ phần tử tiếp theo
    }
}

// Hàm DFS sử dụng đệ quy
void DFS(int node) {
    visited[node] = true;
    nodeStack.push(node); // Đẩy đỉnh vào stack
    dfsResult[resultIndex++] = 'A' + node;

    // Clear area for the node
    setfillstyle(SOLID_FILL, BLACK); // Use background color
    bar(x[node] - 22, y[node] - 22, x[node] + 22, y[node] + 22); // Clear the node area

    for (int i = 0; i < MAX_NODES; i++) {
        if (visited[i]) {
            drawNode(i, GREEN);
        }
        else {
            drawNode(i, LIGHTGRAY);
        }
    }

    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = i + 1; j < MAX_NODES; j++) {
            if (graph[i][j]) {
                drawEdge(i, j);
            }
        }
    }

    drawNode(node, GREEN);
    drawStack();
    delay(2000); // Tăng thời gian trễ lên 2 giây

    for (int i = 0; i < MAX_NODES; i++) {
        if (graph[node][i] && !visited[i]) {
            drawEdge(node, i);
            DFS(i);
        }
    }

    nodeStack.pop(); // Quay lui và bỏ đỉnh khỏi stack

    // Clear area for the node
    setfillstyle(SOLID_FILL, BLACK); // Use background color
    bar(x[node] - 22, y[node] - 22, x[node] + 22, y[node] + 22); // Clear the node area

    for (int i = 0; i < MAX_NODES; i++) {
        if (visited[i]) {
            drawNode(i, YELLOW);
        }
        else {
            drawNode(i, LIGHTGRAY);
        }
    }

    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = i + 1; j < MAX_NODES; j++) {
            if (graph[i][j]) {
                drawEdge(i, j);
            }
        }
    }

    drawNode(node, LIGHTBLUE); // Đổi màu khi kết thúc duyệt
    drawStack();
    delay(2000); // Tăng thời gian trễ lên 2 giây
}

int main() {
    initwindow(600, 400, "Minh Hoa DFS voi Stack");

    for (int i = 0; i < MAX_NODES; i++) {
        drawNode(i, LIGHTGRAY);
    }

    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = i + 1; j < MAX_NODES; j++) {
            if (graph[i][j]) {
                drawEdge(i, j);
            }
        }
    }

    cout << "Nhap dinh bat dau DFS (A-H): ";
    char startNode;
    cin >> startNode;

    DFS(charToIndex(startNode));

    // In kết quả duyệt DFS
    cout << "\nKet qua duyet DFS: ";
    for (int i = 0; i < resultIndex; i++) {
        cout << dfsResult[i] << " ";
    }
    cout << endl;

    getch();
    closegraph();
    return 0;
}
