#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        if (count(a.begin(), a.end(), 0) == 1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        string s;
        bool zero = false;
        for (int x : a) {
            if (x != 0)
                s += 'A';
            else if (zero)
                s += 'B';
            else {
                zero = true;
                s += 'C';
            }
        }
        cout << s << '\n';
    }
}
