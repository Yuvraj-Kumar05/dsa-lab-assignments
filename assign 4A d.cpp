#include <iostream>
using namespace std;

int countStudents(int students[], int sandwiches[], int n) {
    int rotations = 0;
    int studFront = 0, sandTop = 0;
    int total = n;

    while (total > 0 && rotations < total) {
        if (students[studFront] == sandwiches[sandTop]) {
            sandTop++;
            studFront++;
            total--;
            rotations = 0;
        } else {
            int temp = students[studFront];
            for (int i = studFront; i < total - 1; i++)
                students[i] = students[i + 1];
            students[total - 1] = temp;
            rotations++;
        }
    }
    return total;
}

int main() {
    int students[] = {1, 1, 0, 0};
    int sandwiches[] = {0, 1, 0, 1};
    int n = 4;

    cout << countStudents(students, sandwiches, n);
    return 0;
}
