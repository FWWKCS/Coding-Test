#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 100'000
#define MOD 1'000'000'009
using namespace std;

int main() {
    FASTIO;
    
    vector<vector<long long>> dp(4, vector<long long>(MAX+1, 0));
    dp[0][1] = 1, dp[1][0] = 1, dp[1][1] = 1;
    dp[2][0] = 1, dp[2][2] = 1;
    dp[3][0] = 1, dp[3][3] = 1;

    for (int k = 2; k <= MAX; k++) {
        for (int r = 1; r <= 3; r++) {
            int a = k - 2*r;
            if (a < 0) continue;
            else if (a == 0) dp[r][k] = dp[r][0];
            else dp[r][k] = (dp[1][a] + dp[2][a] + dp[3][a]) % MOD;
        }

        dp[0][k] = (dp[1][k] + dp[2][k] + dp[3][k]) % MOD;
    }
    
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        cout << dp[0][n] << '\n';
    }
}