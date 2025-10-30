#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool canTransformToSorted(vector<int> A) {
    stack<int> S;
    vector<int> B;

    vector<int> sortedA = A;
    sort(sortedA.begin(), sortedA.end());
    int i = 0;

    int j = 0;
    int n = A.size();

    while (j < n || !S.empty()) {
        if (!S.empty() && S.top() == sortedA[i]) {
            B.push_back(S.top());
            S.pop();
            i++;
        } else if (j < n) {
            S.push(A[j]);
            j++;
        } else {
            return false;
        }
    }

    return i == n;
}

int main() {
    vector<int> A;
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter elements of array A: ";
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        A.push_back(x);
    }

    if (canTransformToSorted(A))
        cout << "YES, array B can be sorted in ascending order.\n";
    else
        cout << "NO, it is not possible.\n";

    return 0;
}
