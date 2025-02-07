#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N;
int table[100'001][3];
int dp[3] = {0, };

int main() {
    FASTIO;

    int N; cin >> N;
    for (int r = 1; r <= N; r++) {
        cin >> table[r][0] >> table[r][1] >> table[r][2];
    }

    int minV, maxV;

    // min
    dp[0] = table[1][0], dp[1] = table[1][1], dp[2] = table[1][2];

    for (int r = 2; r <= N; r++) {
        int x = table[r][0] + min(dp[0], dp[1]);
        int y = table[r][1] + min(dp[0], min(dp[1], dp[2]));
        int z = table[r][2] + min(dp[1], dp[2]);

        dp[0] = x, dp[1] = y, dp[2] = z;
    }

    minV = min(dp[0], min(dp[1], dp[2]));


    // max
    dp[0] = table[1][0], dp[1] = table[1][1], dp[2] = table[1][2];

    for (int r = 2; r <= N; r++) {
        int x = table[r][0] + max(dp[0], dp[1]);
        int y = table[r][1] + max(dp[0], max(dp[1], dp[2]));
        int z = table[r][2] + max(dp[1], dp[2]);

        dp[0] = x, dp[1] = y, dp[2] = z;
    }

    maxV = max(dp[0], max(dp[1], dp[2]));


    cout << maxV << ' ' << minV;

}