#include <iostream>
#include <vector>
#define INF 1'000'000
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;
    
    int N; cin >> N;
    vector<vector<int>> energy(2, vector<int>(N)), dp(2, vector<int>(N, INF));

    dp[0][0] = 0;
    for (int i = 0; i < N-1; i++) {
        int j, bj; cin >> j >> bj;
        energy[0][i] = j; energy[1][i] = bj;
    }

    int K; cin >> K;

    for (int i = 0; i < N-1; i++) {
        // 1칸 이동
        dp[0][i+1] = min(dp[0][i+1], dp[0][i]+energy[0][i]);
        dp[1][i+1] = min(dp[1][i+1], dp[1][i]+energy[0][i]);

        // 2칸 이동
        dp[0][i+2] = min(dp[0][i+2], dp[0][i]+energy[1][i]);
        dp[1][i+2] = min(dp[1][i+2], dp[1][i]+energy[1][i]);

        // 3칸 도약
        if (i+3 < N) dp[1][i+3] = min(dp[1][i+3], dp[0][i]+K);
    }

    cout << min(dp[0][N-1], dp[1][N-1]);
}