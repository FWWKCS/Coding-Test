#include <iostream>
#define MAX 1515
#define MOD 1'000'000'007
using namespace std;

int dp[MAX+1];

int main() {
    int N; cin >> N;
    
    dp[0] = dp[1] = 0;
    dp[2] = dp[3] = 1;
    
    for (int i = 4; i <= MAX; i++) {
        dp[i] = (((dp[i-2]*2) % MOD) + dp[i-1]) % MOD;
    }

    cout << dp[N];
}