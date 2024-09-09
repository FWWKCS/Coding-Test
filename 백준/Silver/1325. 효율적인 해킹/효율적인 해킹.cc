#include <iostream>
#include <vector>
#include <queue>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int bfs(vector<vector<int>> &graph, vector<int> &visited, int start) {
    int count = 1;
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (auto v : graph[top]) {
            if (visited[v] == 1) continue;

            count++;
            visited[v] = 1;
            q.push(v);
        }
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
        vector<int> visited(N+1, 0);

        L[i] = bfs(graph, visited, i);
        maxC = max(maxC, L[i]);
    }

    for (int i = 1; i <= N; i++) {
        if (L[i] == maxC) cout << i << ' '; 
    }
}