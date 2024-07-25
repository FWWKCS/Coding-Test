#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;
    int N; cin >> N;
    int maze[N];

    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        maze[i] = x;
    }

    vector<int> dp(N, 10'000);
    dp[0] = 0;
    for (int i = 0; i < N-1; i++) {
        for (int k = 1; k <= maze[i] && i+k < N; k++) {
            dp[i+k] = min(dp[i+k], dp[i]+1);
        }
    }

    if (dp[N-1] >= 10'000) cout << -1;
    else cout << dp[N-1];
}