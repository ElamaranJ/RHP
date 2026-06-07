#include <iostream>
using namespace std;

long long ans[2];

long long* getFSMAX(long long dp[][1000], int row, int C) {
    long long fmax = max(dp[row][0], dp[row][1]);
    long long smax = min(dp[row][0], dp[row][1]);

    for (int col = 2; col < C; col++) {
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

            if (row == 0) {
                dp[row][col] = grid[row][col];
            }
        }
    }

    for (int row = 1; row < R; row++) {
        long long* fsmax = getFSMAX(dp, row - 1, C);

        for (int col = 0; col < C; col++) {
            dp[row][col] = grid[row][col] +
                           (dp[row - 1][col] == fsmax[0] ? fsmax[1] : fsmax[0]);
        }
    }

    cout << getFSMAX(dp, R - 1, C)[0];

    return 0;
}