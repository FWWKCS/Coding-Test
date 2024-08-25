#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 100'000
#define MOD 1'000'000'009
using namespace std;

int main() {
    FASTIO;
    
    vector<long long> dp(MAX+1, 0);
    dp[0] = 1, dp[1] = 1; dp[2] = 1; dp[3] = 1;

    for (int i = 2; i <= MAX; i++) {
        if (i >= 2) dp[i] += dp[i-2];
        if (i >= 4) dp[i] += dp[i-4];
        if (i >= 6) dp[i] += dp[i-6];

        dp[i] %= MOD;
    }


    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
}