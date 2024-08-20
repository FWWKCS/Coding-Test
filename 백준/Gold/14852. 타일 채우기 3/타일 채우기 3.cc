#include <iostream>
#include <vector>
#define MAX 1'000'000
#define MOD 1'000'000'007
using namespace std;

int main() {
    int N; cin >> N;

    vector<long long> dp(MAX+1, 1);
    vector<long long> sum(MAX+1, 0);

    dp[1] = 2;
    dp[2] = 7;

    for (int i = 3; i <= N; i++) {
        sum[i] = dp[i-3] + sum[i-1];
        dp[i] = (dp[i-1] * 2 + dp[i-2] * 3 + sum[i] * 2) % MOD;
    }

    cout << dp[N];
}