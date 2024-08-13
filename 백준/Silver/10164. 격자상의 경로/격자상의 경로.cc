#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, K; cin >> N >> M >> K;
    int R = (K / M) + 1, C = K % M;
    if (C == 0) {
        R--;
        C += M;
    }

    vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
    dp[1][1] = 1;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            if (r == 1 && c == 1) continue;

            if (R != 0 && C != 0 && r < R && c > C) dp[r][c] = 0;
            else if (R != 0 && C != 0 && r > R && c < C) dp[r][c] = 0;
            else {
                dp[r][c] = dp[r-1][c] + dp[r][c-1];
            }
        }
    }

    cout << dp[N][M];
}