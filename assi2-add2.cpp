#include <iostream>
#include <string>
using namespace std;

// Check if str is a substring of both s1 and s2
bool isCommonSubstring(const string& str, const string& s1, const string& s2) {
    return s1.find(str) != string::npos && s2.find(str) != string::npos;
}

bool canSplit(const string& s) {
    int n = s.length();

    // Split s into three parts: A [0...i-1], B [i...j-1], C [j...n-1]
    for (int i = 1; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string A = s.substr(0, i);
            string B = s.substr(i, j - i);
            string C = s.substr(j);

            // Ensure all parts are non-empty (already guaranteed by loops)
            if (isCommonSubstring(A, B, C) ||
                isCommonSubstring(B, A, C) ||
                isCommonSubstring(C, A, B)) {
                return true;
                }
        }
    }
    return false;
}
