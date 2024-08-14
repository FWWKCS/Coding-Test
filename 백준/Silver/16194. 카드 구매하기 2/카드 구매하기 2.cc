#include <iostream>
#include <vector>
#define INF 100'000'000
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;
    
    int N; cin >> N;
    vector<int> cost(1, 0);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        cost.push_back(x);
    }

    vector<int> dp(N+1, INF);
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        dp[i] = cost[i];

        for (int j = 1; j <= i; j++) {
            dp[i] = min(dp[i], dp[i-j] + cost[j]);
        }
    }

    cout << dp[N];
}