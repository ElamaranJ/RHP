#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> pre(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> pre[i];
        pre[i] += pre[i - 1];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << pre[b] - pre[a - 1] << '\n';
    }
}
