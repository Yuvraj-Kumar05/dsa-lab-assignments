#include <iostream>
#include <string>
using namespace std;

void generateBinaryNumbers(int n) {
    string q[1000]; // manual queue
    int front = 0, rear = 0;

    q[rear++] = "1"; // enqueue first element

    for (int i = 1; i <= n; i++) {
        string s = q[front++]; // dequeue front
        cout << s << " ";

        // enqueue next two binary numbers
        q[rear++] = s + "0";
        q[rear++] = s + "1";
    }
}

int main() {
    int n = 2;
    generateBinaryNumbers(n);
    return 0;
}
