#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N;

long long solve(vector<vector<int>> &board, vector<vector<long long int>> &dp) {
    dp[0][0] = 1;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (r == N-1 && c == N-1) return dp[r][c];
            
            int delta = board[r][c];
            if (r + delta < N) dp[r+delta][c] += dp[r][c];
            if (c + delta < N) dp[r][c+delta] += dp[r][c];
        }
    }
}

int main() {
    FASTIO;

    cin >> N;
    vector<vector<int>> board(N, vector<int>(N, 0));
    vector<vector<long long int>> dp(N, vector<long long>(N, 0));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x; cin >> x;
            board[i][j] = x;
        }
    }

    long long answer = solve(board, dp);
    cout << answer;
}