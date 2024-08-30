#include <iostream>
#include <vector>
#define INF 1'000'000'009
using namespace std;

int main() {
    int N; cin >> N;
    string block; cin >> block;

    vector<int> dp(N, INF);
    dp[0] = 0;
    for (int i = 1; i < N; i++) {
        for (int k = i-1; k > -1; k--) {
            if (block[i] == 'B' && block[k] == 'J') {
                dp[i] = min(dp[i], dp[k] + (i-k)*(i-k));
            }
            else if (block[i] == 'O' && block[k] == 'B') {
                dp[i] = min(dp[i], dp[k] + (i-k)*(i-k));
            }
            else if (block[i] == 'J' && block[k] == 'O') {
                dp[i] = min(dp[i], dp[k] + (i-k)*(i-k));
            }
        }
    }

    if (dp[N-1] >= INF) cout << -1;
    else cout << dp[N-1];
}