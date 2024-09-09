#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int dfs(vector<vector<int>> &graph, vector<int> &visited, int cur) {
    visited[cur] = 1;
    int count = 1;
    for (auto v : graph[cur]) {
        if (visited[v]) continue;

        count += dfs(graph, visited, v);
    }

    return count;
}

int main() {
    FASTIO;

    int N, M; cin >> N >> M;
    vector<vector<int>> graph(N+1);

    for (int i = 0; i < M; i++) {
        int A, B; cin >> A >> B;
        graph[B].push_back(A);
    }

    int maxC = 0;
    vector<int> L(N+1, -1);
    for (int i = 1; i <= N; i++) {
        // if (relation[i] != minC) continue;
        
        vector<int> visited(N+1, 0);

        L[i] = dfs(graph, visited, i);
        maxC = max(maxC, L[i]);
    }

    for (int i = 1; i <= N; i++) {
        if (L[i] == maxC) cout << i << ' '; 
    }
}