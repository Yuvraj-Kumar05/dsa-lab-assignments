#include <iostream>
#include <vector>
using namespace std;

// Merge function that counts inversions
int mergeAndCount(vector<int>& A, int left, int mid, int right) {
    vector<int> leftSub(A.begin() + left, A.begin() + mid + 1);
    vector<int> rightSub(A.begin() + mid + 1, A.begin() + right + 1);

    int i = 0, j = 0, k = left, invCount = 0;
    int n1 = leftSub.size(), n2 = rightSub.size();

    while (i < n1 && j < n2) {
        if (leftSub[i] <= rightSub[j]) {
            A[k++] = leftSub[i++];
        } else {
            A[k++] = rightSub[j++];
            invCount += n1 - i; // Count inversions
        }
    }

    while (i < n1)
        A[k++] = leftSub[i++];
    while (j < n2)
        A[k++] = rightSub[j++];

    return invCount;
}

// Recursive merge sort function
int mergeSortAndCount(vector<int>& A, int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        invCount += mergeSortAndCount(A, left, mid);
        invCount += mergeSortAndCount(A, mid + 1, right);
        invCount += mergeAndCount(A, left, mid, right);
    }
    return invCount;
}
