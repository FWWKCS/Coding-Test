#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    vector<vector<int>> table(N+1, vector<int>(3, 0)); 
    int r, g, b;
    for (int i = 1; i <= N; i++) {
        cin >> r >> g >> b;
        table[i][0] = r;
        table[i][1] = g;
        table[i][2] = b;
    }

    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(3, vector<int>(3, int(10e6)+1)));
    // start R, G, B
    dp[1][0][0] = table[1][0];
    dp[1][1][1] = table[1][1];
    dp[1][2][2] = table[1][2];

    for (int z = 2; z < N; z++) {
        for (int y = 0; y < 3; y++) { // ~y에서 색 y를 선택
            for (int x = 0; x < 3; x++) { // 시작 색깔이 x인 경우
                if (y == 0) dp[z][y][x] = min(dp[z-1][1][x], dp[z-1][2][x]) + table[z][y];
                else if (y == 1) dp[z][y][x] = min(dp[z-1][0][x], dp[z-1][2][x]) + table[z][y];
                else dp[z][y][x] = min(dp[z-1][0][x], dp[z-1][1][x]) + table[z][y];
            }
        }
    }

    // 마지막으로 R을 선택
    // 시작이 R인 경우를 제외하고 모두 받아온다
    dp[N][0][1] = min(dp[N-1][1][1], dp[N-1][2][1]) + table[N][0]; // 시작이 G인 경우
    dp[N][0][2] = min(dp[N-1][1][2], dp[N-1][2][2]) + table[N][0]; // 시작이 B인 경우

    // 마지막으로 G를 선택
    // 시작이 G인 경우를 제외하고 모두 받아온다
    dp[N][1][0] = min(dp[N-1][0][0], dp[N-1][2][0]) + table[N][1]; // 시작이 R인 경우
    dp[N][1][2] = min(dp[N-1][0][2], dp[N-1][2][2]) + table[N][1]; // 시작이 B인 경우

    // 마지막으로 B를 선택
    // 시작이 B인 경우를 제외하고 모두 받아온다
    dp[N][2][0] = min(dp[N-1][0][0], dp[N-1][1][0]) + table[N][2]; // 시작이 R인 경우
    dp[N][2][1] = min(dp[N-1][0][1], dp[N-1][1][1]) + table[N][2]; // 시작이 G인 경우

    int answer = int(10e7);

    for (auto x : dp[N]) {
        for (auto y : x) {
            answer = min(answer, y);
        }
    }

    cout << answer;
}