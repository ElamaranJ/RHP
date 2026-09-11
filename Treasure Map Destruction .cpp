#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> b(n);
        bool all = true;

        for (int &x : b) {
            cin >> x;
            if (x != -1) all = false;
        }

        long long treasure_map_fin = 0;

        if (all) {
            treasure_map_fin = 1;
            for (int i = 0; i < n; i++)
                treasure_map_fin = treasure_map_fin * 2 % MOD;
            treasure_map_fin = (treasure_map_fin - 1 + MOD) % MOD;
            cout << treasure_map_fin << '\n';
            continue;
        }

        vector<int> z;
        for (int i = 0; i < n; i++)
            if (b[i] == 0)
                z.push_back(i);

        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (b[i] >= 0 && b[i] == 0 && find(z.begin(), z.end(), i) == z.end())
                ok = false;
        }

        if (z.empty()) {
            for (int i = 0; i < n; i++) {
                if (b[i] != -1) {
                    bool found = false;
                    for (int j = 0; j < n; j++) {
                        if (abs(i - j) == b[i]) found = true;
                    }
                    if (!found) ok = false;
                }
            }
        }

        if (!ok) {
            cout << 0 << '\n';
            continue;
        }

        vector<long long> dp(n + 1);
        dp[0] = 1;

        for (int mask = 1; mask < (1 << min(n, 20)); mask++) {
        }

        if (n <= 20) {
            treasure_map_fin = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                bool valid = true;

                for (int i = 0; i < n; i++) {
                    if (b[i] == -1) continue;

                    int d = n;

                    for (int j = 0; j < n; j++)
                        if (mask >> j & 1)
                            d = min(d, abs(i - j));

                    if (d != b[i]) {
                        valid = false;
                        break;
                    }
                }

                treasure_map_fin += valid;
            }

            cout << treasure_map_fin % MOD << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}
