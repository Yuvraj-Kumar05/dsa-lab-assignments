#include <iostream>
using namespace std;

int getMinIndex(int q[], int n, int sortedIndex) {
    int min_index = -1, min_val = INT_MAX;
    for (int i = 0; i < n; i++) {
        int curr = q[0];
        for (int j = 0; j < n - 1; j++) q[j] = q[j + 1];
        n--;

        if (curr <= min_val && i <= sortedIndex) {
            min_val = curr;
            min_index = i;
        }

        q[n++] = curr;
    }
    return min_index;
}

void insertMinToRear(int q[], int n, int min_index) {
    int min_val;
    for (int i = 0; i < n; i++) {
        int curr = q[0];
        for (int j = 0; j < n - 1; j++) q[j] = q[j + 1];
        n--;

        if (i == min_index) {
            min_val = curr;
        } else {
            q[n++] = curr;
        }
    }
    q[n++] = min_val;
}

void sortQueue(int q[], int n) {
    for (int i = 0; i < n; i++) {
        int min_index = -1, min_val = INT_MAX;
        for (int j = 0; j < n - i; j++) {
            if (q[j] < min_val) {
                min_val = q[j];
                min_index = j;
            }
        }

        int temp = q[min_index];
        for (int j = min_index; j < n - i - 1; j++) {
            q[j] = q[j + 1];
        }
        q[n - i - 1] = temp;
    }
}

int main() {
    int q[] = {11, 5, 4, 21};
    int n = 4;
    sortQueue(q, n);

    for (int i = 0; i < n; i++)
        cout << q[i] << " ";
    return 0;
}
