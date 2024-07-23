#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 100'000
using namespace std;

int main() {
    FASTIO;

    int N; cin >> N;
    int seq[N];
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        seq[i] = x;
    }

    // row 0 : increase
    // row 1 : decrease
    vector<vector<int>> dp(2, vector<int>(N, 1));
    int answer = 1;
    for (int i = 1; i < N; i++) {
        if (seq[i] >= seq[i-1]) dp[0][i] = dp[0][i-1] + 1;
        if (seq[i] <= seq[i-1]) dp[1][i] = dp[1][i-1] + 1;

        answer = max(answer, max(dp[0][i], dp[1][i]));
    }

    cout << answer;
}