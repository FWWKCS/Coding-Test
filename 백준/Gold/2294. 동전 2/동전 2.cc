#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 10'001
using namespace std;

int main() {
    FASTIO;

    int n, k; cin >> n >> k;
    vector<int> coin(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        coin[i] = x;
    }
    
    vector<int> dp(k+1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int x = coin[i]; x <= k; x++) {
            dp[x] = min(dp[x], dp[x-coin[i]] + 1);
        }
    }

    if (dp[k] >= INF) cout << -1;
    else cout << dp[k]; 
}