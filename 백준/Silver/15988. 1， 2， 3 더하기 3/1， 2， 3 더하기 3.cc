#include <iostream>
#define MOD 1'000'000'009
#define MAX 1'000'000
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;
    int T; cin >> T;

    long long dp[MAX+1];
    dp[0] = 1; dp[1] = 1; dp[2] = 2;
    for (int i = 3; i <= MAX; i++) {
        dp[i] = (dp[i-3] + dp[i-2] + dp[i-1]) % MOD;
    }

    for (int i = 0; i < T; i++) {
        int q; cin >> q;
        cout << dp[q] << '\n';
    }
}