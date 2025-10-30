#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);
    stack<int> s;

    for (int i = n - 1; i >= 0; --i) {

        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        result[i] = s.empty() ? -1 : s.top();

        s.push(arr[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    vector<int> nge = nextGreaterElement(arr);

    cout << "Input: ";
    for (int num : arr) cout << num << " ";
    cout << "\nNext Greater Elements: ";
    for (int val : nge) cout << val << " ";
    cout << endl;

    return 0;
}
