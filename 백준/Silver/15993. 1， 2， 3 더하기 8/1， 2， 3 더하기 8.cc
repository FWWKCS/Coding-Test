#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 100'000
#define MOD 1'000'000'009
using namespace std;

int main() {
    FASTIO;

    vector<vector<long long>> dp(2, vector<long long>(MAX+1, 0));
    dp[0][1] = 1;
    dp[0][2] = 1, dp[1][2] = 1;
    dp[0][3] = 2, dp[1][3] = 2;
    
    for (int c = 4; c <= MAX; c++) {
        dp[0][c] = (dp[1][c-3] + dp[1][c-2] + dp[1][c-1]) % MOD;
        dp[1][c] = (dp[0][c-3] + dp[0][c-2] + dp[0][c-1]) % MOD;
    }

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        cout << dp[0][n] << ' ' << dp[1][n] << '\n';
    }
}