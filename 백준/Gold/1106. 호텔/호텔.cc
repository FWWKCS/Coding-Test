#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1'000'000
using namespace std;

int main() {
    FASTIO;

    int C, N; cin >> C >> N;
    vector<pair<int, int>> data = { make_pair(INF, INF) };
    vector<vector<int>> dp(N+1, vector<int>(C+1, INF));

    for (int i = 0; i < N; i++) {
        int p, v; cin >> p >> v;
        data.push_back(make_pair(p, v));
    }

    for (int r = 1; r <= N; r++) {
        for (int k = 1; k <= C; k++) {
            int own, p = data[r].first, v = data[r].second;
            if (k % v != 0) own = ((k / v) + 1) * p;
            else own = (k / v) * p;

            dp[r][k] = min(dp[r-1][k], own);
            if (k - v >= 0) dp[r][k] = min(min(dp[r][k], dp[r-1][k-v] + p), dp[r][k-v] + p);
        }
    }

    cout << dp[N][C];
}