#include <iostream>
#define MOD 1'000'000'000
using namespace std;

int dp[1'000'001];

int main() {
    int N; cin >> N;

    dp[0] = dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        if (i % 2 == 0) dp[i] = (dp[i-1] + dp[i/2]) % MOD;
        else dp[i] = dp[i-1];
    }

    cout << dp[N];
}