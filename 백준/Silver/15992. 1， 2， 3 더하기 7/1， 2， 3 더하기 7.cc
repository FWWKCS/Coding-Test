#include <iostream>
#include <vector>
#define MAX 1000
#define MOD 1'000'000'009
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    vector<vector<long long>> dp(MAX+1, vector<long long>(MAX+1, 0));
    dp[1][1] = 1, dp[1][2] = 1, dp[1][3] = 1;
    dp[2][2] = 1;

    for (int c = 3; c <= MAX; c++) {
        for (int r = 2; r <= c; r++) {
            dp[r][c] = (dp[r-1][c-3] + dp[r-1][c-2] + dp[r-1][c-1]) % MOD;
        }
    }

    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        cout << dp[m][n] << '\n';
    }
}