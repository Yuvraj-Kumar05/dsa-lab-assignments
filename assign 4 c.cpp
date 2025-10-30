#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    int half = n / 2;
    queue<int> first, second;

    // Split into two halves
    for (int i = 0; i < half; i++) { first.push(q.front()); q.pop(); }
    while (!q.empty()) { second.push(q.front()); q.pop(); }

    // Interleave
    while (!first.empty() || !second.empty()) {
        if (!first.empty()) { q.push(first.front()); first.pop(); }
        if (!second.empty()) { q.push(second.front()); second.pop(); }
    }
}

int main() {
    queue<int> q;
    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) { cin >> val; q.push(val); }

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) { cout << q.front() << " "; q.pop(); }
    cout << endl;
}
