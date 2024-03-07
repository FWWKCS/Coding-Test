#include <bits/stdc++.h>
using namespace std;

int main() {
    int K; cin >> K;
    vector<vector<int>> dp(K+1, vector<int>(2, 0));
    dp[0] = {1, 0};

    for (int i = 1; i <= K; i++) {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = dp[i-1][0] + dp[i-1][1];
    }

    cout << dp[K][0] << ' ' << dp[K][1];
}