#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;

int N;
int main() {
    FASTIO;

    cin >> N;
    int board[N+1][N+1];
    vector<vector<vector<ll>>> dp(3, vector<vector<ll>>(N+1, vector<ll>(N+1, 0)));
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> board[r][c];
        }
    }

    // dp[z][r][c]: r행 c열 위치에 도달하여 z 방식으로 파이프를 설치하는 경우의 수
    // z = 0: 가로, z = 1: 세로, z = 2: 대각선

    dp[0][1][2] = 1;
    for (int i = 3; i <= N; i++) {
        if (board[1][i]) break;
        dp[0][1][i] = 1;
    }

    for (int r = 2; r <= N; r++) {
        for (int c = 2; c <= N; c++) {
            // 가로로 도착
            if (!board[r][c]) dp[0][r][c] += dp[0][r][c-1] + dp[2][r][c-1];

            // 세로로 도착
            if (!board[r][c]) dp[1][r][c] += dp[1][r-1][c] + dp[2][r-1][c];

            // 대각선으로 도착
            if (!board[r][c] && !board[r-1][c] && !board[r][c-1] && !board[r-1][c-1])
                dp[2][r][c] += dp[0][r-1][c-1] + dp[1][r-1][c-1] + dp[2][r-1][c-1]; 
        }
    }

    cout << dp[0][N][N] + dp[1][N][N] + dp[2][N][N];
}