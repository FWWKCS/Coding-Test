#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void dfs(vector<vector<int>> &link, vector<int> &parent, vector<bool> &visited, int cur) {
    visited[cur] = true;

    for (auto v : link[cur]) {
        if (visited[v]) continue;
        parent[v] = cur;
        dfs(link, parent, visited, v);
    }
}

int main() {
    FASTIO;

    int N; cin >> N;
    vector<vector<int>> link(N+1);
    for (int i = 0; i < N-1; i++) {
        int x, y; cin >> x >> y;
        link[x].push_back(y);
        link[y].push_back(x);
    }

    vector<int> parent(N+1, 0);
    vector<bool> visited(N+1, false);
    dfs(link, parent, visited, 1);

    for (int i = 2; i <= N; i++) cout << parent[i] << '\n';
}