#include <iostream>
#include <string>
using namespace std;

bool isPangram(string str) {
    int flag = 0;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        if (ch >= 'a' && ch <= 'z') {
            flag |= (1 << (ch - 'a'));
        }
    }

    return flag == ((1 << 26) - 1);
}

int main() {
    string str;
    getline(cin, str);

    cout << (isPangram(str) ? "true" : "false") << endl;

    return 0;
}