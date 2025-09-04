#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;

    int n = strlen(str);
    for (int i = n - 1; i >= 0; i--)
        cout << str[i];
    cout << endl;
}
