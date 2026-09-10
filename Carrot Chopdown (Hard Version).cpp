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

        vector<int> cnt(m + 1);
        long long sum = 0;

        for (int i = 0, x; i < n; i++) {
            cin >> x;
            cnt[x]++;
            sum += x;
        }

        vector<int> pre(m + 1);

        for (int i = 1; i <= m; i++)
            pre[i] = pre[i - 1] + cnt[i];

        long long p = 2;
        bool done = false;

        for (int k = 1; k <= m; k++) {
            if (done) {
                cout << sum << " ";
                continue;
            }

            if (p > m) {
                cout << sum << " ";
                done = true;
                continue;
            }

            long long ans = 0;

            for (int s = 1; s <= m; s++) {
                long long cur = 0;
                int lim = min((long long)m / s, p - 2);

                for (int q = 1; q <= lim; q++) {
                    int l = q * s;
                    int r = min(m, (q + 1) * s - 1);
                    cur += 1LL * q * (pre[r] - pre[l - 1]);
                }

                long long l = (p - 1) * s;

                if (l <= m)
                    cur += (p - 1) * (pre[m] - pre[l - 1]);

                if (p * s <= m)
                    cur += cnt[p * s];

                ans = max(ans, cur);
            }

            cout << ans << " ";

            if (p > m / 2)
                p = m + 1;
            else
                p *= 2;
        }

        cout << '\n';
    }
}
