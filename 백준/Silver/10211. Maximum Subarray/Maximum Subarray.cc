#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        int X[N], dp[N];
        int answer = -1'000'000;

        for (int i = 0; i < N; i++) {
            int x; cin >> x;
            X[i] = x; dp[i] = x;

            dp[i] = max(dp[i-1]+x, dp[i]);
            answer = max(answer, dp[i]);
        }

        cout << answer << '\n';
    }
}