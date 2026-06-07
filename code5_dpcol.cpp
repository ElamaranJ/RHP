#include <iostream>
using namespace std;

long long* getFSMAX(long long dp[][1000], int R, int col) {
    static long long ans[2];

    long long fmax = max(dp[0][col], dp[1][col]);
    long long smax = min(dp[0][col], dp[1][col]);

    for (int row = 2; row < R; row++) {
        if (dp[row][col] > fmax) {
            smax = fmax;
            fmax = dp[row][col];
        } else if (dp[row][col] > smax) {
            smax = dp[row][col];
        }
    }

    ans[0] = fmax;
    ans[1] = smax;
    return ans;
}

int main() {
    int R, C;
    cin >> R >> C;

    int grid[1000][1000];
    long long dp[1000][1000];

    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            cin >> grid[row][col];
            if (col == 0)
                dp[row][col] = grid[row][col];
        }
    }

    for (int col = 1; col < C; col++) {
        long long* fsmax = getFSMAX(dp, R, col - 1);

        for (int row = 0; row < R; row++) {
            dp[row][col] = grid[row][col] +
                           (dp[row][col - 1] == fsmax[0] ? fsmax[1] : fsmax[0]);
        }
    }

    cout << getFSMAX(dp, R, C - 1)[0];

    return 0;
}