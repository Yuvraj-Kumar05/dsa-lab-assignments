#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int countDistinctElements(const vector<int>& arr) {
    unordered_set<int> uniqueElements;

    for (int val : arr) {
        uniqueElements.insert(val);
    }

    return uniqueElements.size();
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int count = countDistinctElements(arr);
    cout << "Total number of distinct elements: " << count << endl;

    return 0;
}
