#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> cnt(m + 1), suf(m + 2);
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            cnt[x]++;
        }
        for (int i = m; i >= 1; i--)
            suf[i] = suf[i + 1] + cnt[i];
        int ans = 0;
        for (int x = 1; x <= m; x++) {
            int cur = suf[x];
            if (2 * x <= m)
                cur += cnt[2 * x];
            ans = max(ans, cur);
        }
        cout << ans << '\n';
    }
}
