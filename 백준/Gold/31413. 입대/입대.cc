#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N, M;
int A, D;

int main() {
    FASTIO;

    cin >> N >> M;
    vector<int> s(N+1, 0);
    
    for (int i = 1; i <= N; i++) cin >> s[i];
    cin >> A >> D;
    vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
  
    for (int i = 1; i <= N; i++) dp[i][0] = dp[i-1][0]+s[i];

    for (int r = D; r < N+1; r++) {
        for (int c = 1; c <= N; c++) {
            dp[r][c] = max(dp[r-1][c]+s[r], dp[r-D][c-1]+A);
            if (r == N) {
                // 막타 처리
                for (int k = r-D+1; k < r; k++) {
                    dp[r][c] = max(dp[r][c], dp[k][c-1]+A);
                }
            }
        }
    }

    for (int i = 0; i <= N; i++) {
        if (dp[N][i] >= M) {
            cout << i;
            return 0;
        }
    }

    cout << -1;
}