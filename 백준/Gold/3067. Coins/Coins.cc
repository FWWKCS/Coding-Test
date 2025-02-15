#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int T; 
int N, M;

vector<vector<int>> dp(21, vector<int>(10'001, 0));

vector<int> coins(21);

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) 
            cin >> coins[i];

        cin >> M;
        for (int r = 1; r <= N; r++) {
            for (int c = 0; c <= M; c++) {
                if (!c) {
                    dp[r][c] = 1;
                    continue;
                }

                if (c >= coins[r]) dp[r][c] = dp[r-1][c] + dp[r][c-coins[r]];
                else dp[r][c] = dp[r-1][c];
            }
        }

        cout << dp[N][M] << '\n';
    }
}