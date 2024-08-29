#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N, S, M; cin >> N >> S >> M;
    vector<int> V(N, 0);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        V[i] = x;
    }
    
    vector<vector<bool>> dp(N+1, vector<bool>(M+1, false));
    dp[0][S] = true;
    
    for (int r = 0; r < N; r++) {
        for (int c = 0; c <= M; c++) {
            if (dp[r][c]) {
                if (c + V[r] <= M) dp[r+1][c + V[r]] = true;
                if (c - V[r] >= 0) dp[r+1][c - V[r]] = true;
            }
        }
    }

    for (int i = M; i > -1; i--) {
        if (dp[N][i] == true) {
            cout << i;
            return 0;
        }
    }

    cout << -1;
}