#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

vector<vector<int>> g, dp;
vector<int> w, answer;

void dfs(int cur) {
    
    dp[cur][1] = w[cur];

    for (int k : g[cur]) {
        dfs(k);
        dp[cur][0] = dp[cur][0] + max(dp[k][0], dp[k][1]);
        dp[cur][1] += dp[k][0];
    }
}

void trace(int cur, bool include) {
    if (include) {
        answer.push_back(cur);
        for (int k : g[cur]) {
            trace(k, false);
        }
    }
    else {
        for (int k : g[cur]) {
            if (dp[k][0] > dp[k][1]) trace(k, false);
            else trace(k, true);
        }
    }
}


int main() {
    FASTIO;

    int n; cin >> n;
    g.resize(n+1);
    dp.resize(n+1, vector<int>(2, 0));
    w.resize(n+1, 0);
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        if (x < y) g[x].push_back(y);
        else g[y].push_back(x);
    } 

    vector<int> S;
    dfs(1);
    
    cout << max(dp[1][0], dp[1][1]) << '\n';
    
    if (dp[1][0] > dp[1][1]) trace(1, false);
    else trace(1, true);

    sort(answer.begin(), answer.end());
    for (int x : answer) cout << x << ' ';
}