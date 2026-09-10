#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    int sz = 1;
    while (sz < n) sz *= 2;

    vector<long long> seg(2 * sz, 1e18);

    for (int i = 0; i < n; i++)
        cin >> seg[sz + i];

    for (int i = sz - 1; i > 0; i--)
        seg[i] = min(seg[2 * i], seg[2 * i + 1]);

    while (q--) {
        int a, b;
        cin >> a >> b;
        a = a - 1 + sz;
        b = b - 1 + sz;

        long long ans = 1e18;

        while (a <= b) {
            if (a % 2 == 1) ans = min(ans, seg[a++]);
            if (b % 2 == 0) ans = min(ans, seg[b--]);
            a /= 2;
            b /= 2;
        }

        cout << ans << '\n';
    }
}
