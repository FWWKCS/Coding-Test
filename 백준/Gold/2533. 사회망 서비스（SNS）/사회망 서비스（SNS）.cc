#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int N; 
int u, v;
vector<vector<int>> dp;
vector<vector<int>> t;

void recursion(int cur, int root) {
    for (int next : t[cur]) {
        if (next == root) continue;
        recursion(next, cur);
        dp[cur][0] += dp[next][1];
        dp[cur][1] += min(dp[next][0], dp[next][1]);
    }

    dp[cur][1]++;
}

int main() {
    FASTIO;

    cin >> N;
    dp.resize(N+1, vector<int>(2, 0));
    t.resize(N+1, {});

    for (int _ = 0; _ < N-1; _++) {
        cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }

    recursion(1, -1);

    cout << min(dp[1][0], dp[1][1]);
}