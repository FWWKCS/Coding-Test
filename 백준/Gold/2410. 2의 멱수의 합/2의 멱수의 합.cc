#include <iostream>
#include <vector>
#include <math.h>
#define MOD 1'000'000'000
using namespace std;

vector<vector<int>> dp;

int main() {
    int N; cin >> N;

    dp.resize(20, vector<int>(N+1, 1));
    
    for (int i = 2; i <= N; i++) {
        for (int k = 1; k <= 19; k++) {
            int target = i-pow(2, k);
            if (target >= 0) {
                dp[k][i] = (dp[k-1][i] + dp[k][target]) % MOD;
            }
            else dp[k][i] = dp[k-1][i];
        }
    }

    cout << dp[19][N];
}