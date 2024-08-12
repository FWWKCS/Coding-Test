#include <iostream>
#include <vector>
#define MAX 1000
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int players[MAX+1][2] = {0};
    int idx = 1, white, black;
    while (cin >> white >> black) {
        players[idx][0] = white;
        players[idx][1] = black;
        idx++;
    }

    vector<vector<vector<int>>> dp(idx, vector<vector<int>>(16, vector<int>(16, 0)));
    // int dp[idx][limit+1][limit+1];
    // z번 플레이어까지 백 r명, 흑 c명 편성할 때 점수의 최댓값

    for (int z = 1; z < idx; z++) {
        for (int w = 0; w <= 15; w++) {
            for (int b = 0; b <= 15; b++) {
                if (w+b > z) {
                    if (w == 0) dp[z][w][b] = dp[z][w][b-1];
                    else if (b == 0) dp[z][w][b] = dp[z][w-1][b];
                    else dp[z][w][b] = max(dp[z][w-1][b], dp[z][w][b-1]);

                    continue;
                }

                // z번 플레이어 선택
                // w로 편성
                if (w != 0) {
                    dp[z][w][b] = max(dp[z][w][b], dp[z-1][w-1][b] + players[z][0]);
                }

                // b로 편성
                if (b != 0) {
                    dp[z][w][b] = max(dp[z][w][b], dp[z-1][w][b-1] + players[z][1]);
                }

                // z번 플레이어 선택X
                dp[z][w][b] = max(dp[z-1][w][b], dp[z][w][b]);
            }
        }
    }

    cout << dp[idx-1][15][15];
}