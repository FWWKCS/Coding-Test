#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MOD 1'000'000'009
using namespace std;

int main() {
    FASTIO;

    int T; cin >> T;
    int dp[4][100'001] = {
        {0, },
        {0, 1, },
        {0, 0, 1, },
        {0, 0, 0, 1, }
    };

    for (int k = 2; k <= 100'000; k++) {
        dp[1][k] = (dp[2][k-1] + dp[3][k-1]) % MOD;

        if (k > 2) dp[2][k] = (dp[1][k-2] + dp[3][k-2]) % MOD;
        if (k > 3) dp[3][k] = (dp[1][k-3] + dp[2][k-3]) % MOD;
    }

    while (T--) {
        int n; cin >> n;
        cout << ((dp[1][n] + dp[2][n]) % MOD + dp[3][n]) % MOD << '\n';
    }
}