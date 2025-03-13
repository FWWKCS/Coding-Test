#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;

int N;
int u, v;

vector<ll> res;
vector<vector<int>> t;

vector<vector<ll>> dp;

void recursion(int root, int cur) {
    for (int next : t[cur]) {
        if (next == root) continue;
        recursion(cur, next);

        dp[cur][0] += max(dp[next][0], dp[next][1]);
        dp[cur][1] += dp[next][0];
    }

    dp[cur][1] += res[cur];
}

int main() {
    FASTIO;

    cin >> N;
    res.resize(N+1);
    for (auto i = res.begin()+1; i < res.end(); i++) cin >> *i;
    
    dp.resize(N+1, vector<ll>(2, 0));

    t.resize(N+1, {});
    for (int i = 0; i < N-1; i++) {
        cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }

    recursion(-1, 1);

    cout << max(dp[1][0], dp[1][1]);
}