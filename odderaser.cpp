#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<long long> a(n);

        for (auto &x : a) cin >> x;

        cout << gcd(a[0], a[n - 1]) << '\n';
    }
}
