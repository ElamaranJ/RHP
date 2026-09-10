#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int n, q;
        cin >> n >> q;

        vector<int> A(n);
        for (int &x : A) cin >> x;

        vector<int> mp(100001);
        iota(mp.begin(), mp.end(), 0);

        cout << "Case " << tc << ":\n";

        while (q--) {
            int type;
            cin >> type;

            if (type == 1) {
                int x, y;
                cin >> x >> y;

                for (int i = 1; i <= 100000; i++)
                    if (mp[i] == x)
                        mp[i] = y;
            }
            else {
                int idx;
                cin >> idx;
                cout << mp[A[idx - 1]] << '\n';
            }
        }
    }
}
