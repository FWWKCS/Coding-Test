#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int T; 
int N, M;

vector<int> dp;
vector<int> coins;

int main() {
    FASTIO;

    cin >> T;
    while (T--) {
        cin >> N;
        coins.resize(N);
        for (auto &x : coins) cin >> x;
        
        cin >> M;
        dp.clear();
        dp.resize(M+1, 0);
        dp[0] = 1;

        for (int v = 0; v < N; v++) {
            for (int k = coins[v]; k <= M; k++) {
                dp[k] += dp[k-coins[v]];
            }
        }

        cout << dp[M] << '\n';
    }
}