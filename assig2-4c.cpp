#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[] = "Hello World";
    char result[50];
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (c!='a' && c!='e' && c!='i' && c!='o' && c!='u')
            result[j++] = str[i];
    }
    result[j] = '\0';

    cout << "String without vowels: " << result;
    return 0;
}
