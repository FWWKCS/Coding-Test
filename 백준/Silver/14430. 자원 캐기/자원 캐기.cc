#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int dp[301][301] = {0, };

int main() {
    FASTIO;

    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int x; cin >> x;
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + x;
        }
    }

    cout << dp[N][M];
}