#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;
        
    int N; cin >> N;
    vector<int> T(N+1, 0), P(N+1, 0), dp(N+2, 0);

    for (int i = 1; i <= N; i++) {
        int t, p; cin >> t >> p;
        T[i] = t, P[i] = p;
    }

    for (int k = N; k > 0; k--) {
        if (k + T[k] <= N+1) {
            dp[k] = max(dp[k+1], P[k]+dp[k+T[k]]);
        }
        else dp[k] = dp[k+1];
    }

    cout << dp[1];
}