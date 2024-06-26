#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<long long> dp(n+1, 0);
    dp[0] = 1, dp[1] = 1, dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i-3] + dp[i-1]) % 1'000'000'009;
    }

    cout << dp[n];
}