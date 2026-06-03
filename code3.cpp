#include <iostream>
#include <string>
using namespace std;

void printCombinations(string str) {
    int n = str.length();

    for (int mask = 1; mask < (1 << n); mask++) {
        string comb = "";

        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) > 0) {
                comb += str[i];
            }
        }

        cout << comb << endl;
    }
}

int main() {
    string str;
    getline(cin, str);

    printCombinations(str);

    return 0;
}