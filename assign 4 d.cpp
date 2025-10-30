#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;
    unordered_map<char, int> freq;

    for (char c : str) {
        q.push(c);
        freq[c]++;

        while (!q.empty() && freq[q.front()] > 1) q.pop();

        if (!q.empty()) cout << q.front() << " ";
        else cout << -1 << " ";
    }
}

int main() {
    string s;
    cout << "Enter string (with spaces removed): ";
    cin >> s;
    firstNonRepeating(s);
    cout << endl;
}
