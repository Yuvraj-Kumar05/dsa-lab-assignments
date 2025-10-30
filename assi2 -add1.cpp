#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int countPairsWithDiffK(const vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    int count = 0;

    for (int num : arr) {
        if (freq.count(num - k)) count += freq[num - k];
        if (freq.count(num + k)) count += freq[num + k];

        freq[num]++;
    }

    return count;
}
