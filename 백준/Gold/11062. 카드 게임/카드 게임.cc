#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int answer = 0;
vector<int> board;
vector<vector<int>> dp;

int solve(int N) {
    // 초기화
    if (N % 2) {
        // 카드가 1개 남을때 근우의 턴
        // 1개만 있을때 근우의 최대 점수
        for (int i = 0; i < N; i++) {
            dp[i][i] = board[i];
        }
    }

    for (int k = 1; k < N; k++) {
        for (int l = 0; l < N-k; l++) {
            int r = l+k;
            if ((N - k) % 2) {
                // 남은 board 범위가 (l, r)일때 근우의 턴
                dp[l][r] = max(
                    // 1. l 방향의 카드를 선택하거나
                    dp[l+1][r] + board[l],
                    // 2. r 방향의 카드를 선택하거나
                    dp[l][r-1] + board[r]
                );
            }
            else {
                // 명우의 턴
                // 근우의 점수를 최소가 되게 하도록
                dp[l][r] = min(dp[l+1][r], dp[l][r-1]);
            }
        }
    }

    return dp[0][N-1];
}

int main() {
    FASTIO;

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        board.resize(N);
        dp.resize(N, vector<int>(N, 0));
        for (auto &x : board) cin >> x;

        cout << solve(N) << '\n';
        board.clear();
        dp.clear();
    }
}