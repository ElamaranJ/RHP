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
        vector<int> a(n), one;
        for (int &x : a) {
            cin >> x;
            if (x == 1) one.push_back(&x - &a[0]);
        }
        int l = -1, r = -1, best = 0;
        auto upd = [&](int x, int y) {
            if (x != -1 && y != -1 && y - x + 1 > best) {
                best = y - x + 1;
                l = x;
                r = y;
            }
        };
        if (one.empty()) {
            for (int i = 0; i < n; i++)
                if (a[i] == -1) {
                    if (l == -1) l = i;
                    r = i;
                }
            if (l == -1) l = r = 0;
        } else {
            int first = one[0], last = one.back();

            int x = -1;
            for (int i = 0; i < first; i++)
                if (a[i] == -1) {
                    x = i;
                    break;
                }
            upd(x, first);
            for (int i = 0; i + 1 < one.size(); i++)
                upd(one[i], one[i + 1]);
            x = -1;
            for (int i = n - 1; i > last; i--)
                if (a[i] == -1) {
                    x = i;
                    break;
                }
            upd(last, x);
            if (l == -1) l = r = one[0];
        }
        for (int &x : a)
            if (x == -1) x = 0;
        a[l] = a[r] = 1;
        for (int x : a)
            cout << x << ' ';
        cout << '\n';
    }
}
