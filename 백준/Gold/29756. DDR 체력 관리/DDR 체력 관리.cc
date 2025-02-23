#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<vector<int>> dp;
int N, K;

int main() {
    FASTIO;

    cin >> N >> K;
    dp.resize(N+1, vector<int>(101, 0));

    vector<int> S(N);
    for (auto &x : S) cin >> x;
    
    vector<int> H(N);
    for (auto &x : H) cin >> x;

    for (int i = 0; i < N; i++) {
        int s = S[i], h = H[i];
        for (int t = 0; t <= 100; t++) {
            // 구간을 넘기기
            dp[i+1][min(100, t+K)] = max(dp[i+1][min(100, t+K)], dp[i][t]);
            
            // 구간을 수행
            if (t >= h) {
                dp[i+1][min(100, t-h+K)] = max(dp[i+1][min(100, t-h+K)], dp[i][t] + s);
            }
        }
    }

    int answer = 0;
    for (int i = 0; i <= 100; i++) {
        answer = max(answer, dp[N][i]);
    }

    cout << answer;
}