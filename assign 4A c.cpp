#include <iostream>
using namespace std;

bool checkSorted(int q[], int n) {
    int st[100];
    int top = -1;
    int expected = 1;
    int frontIndex = 0;

    while (frontIndex < n) {
        int front = q[frontIndex++];

        if (front == expected) {
            expected++;
        } else {
            while (top >= 0 && st[top] == expected) {
                top--;
                expected++;
            }
            if (top >= 0 && st[top] < front)
                return false;
            st[++top] = front;
        }
    }

    while (top >= 0) {
        if (st[top] != expected)
            return false;
        top--;
        expected++;
    }

    return true;
}

int main() {
    int q[] = {5, 1, 2, 3, 4};
    int n = 5;

    if (checkSorted(q, n))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
