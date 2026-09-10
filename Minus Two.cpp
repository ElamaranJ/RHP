#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0, odd = 0, e0 = 0, e2 = 0;
        cin >> n;
        map<long long, int> mp;
        while (n--) {
            long long x;
            cin >> x;
            ans = max(ans, ++mp[x]);
            if (x % 2)
                odd++;
            else if (x % 4 == 0)
                e0++;
            else
                e2++;
        }
        cout << max({ans, odd, e0, e2}) << '\n';
    }
}
