#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nearestSmallerToLeft(const vector<int>& A) {
    vector<int> result;
    stack<int> s;

    for (int i = 0; i < A.size(); ++i) {
        // Pop elements that are >= current A[i]
        while (!s.empty() && s.top() >= A[i]) {
            s.pop();
        }

        if (s.empty())
            result.push_back(-1);
        else
            result.push_back(s.top());

        s.push(A[i]);
    }

    return result;
}

int main() {
    vector<int> A = {4, 5, 2, 10, 8};
    vector<int> output = nearestSmallerToLeft(A);

    cout << "Input: ";
    for (int x : A) cout << x << " ";
    cout << "\nOutput: ";
    for (int x : output) cout << x << " ";
    cout << endl;

    return 0;
}
