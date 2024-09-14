#include <iostream>
#include <vector>
#include <queue>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void bfs(vector<vector<int>> &graph, vector<int> &rel, int start) {
    queue<int> q;
    q.push(start);
    vector<int> visited(graph.size(), 0);
    visited[start] = 1;

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (int i = 1; i < graph.size(); i++) {
            if (graph[top][i] == -1 || visited[i]) continue;

            visited[i] = 1;
            rel[start]--;
            rel[i]--;
            q.push(i);
        }
    }
}

int main() {
    FASTIO;

    int N, M; cin >> N >> M;
    vector<vector<int>> graph(N+1, vector<int>(N+1, -1));
    vector<int> rel(N+1, N-1);
    for (int i = 0; i < M; i++) {
        int A, B; cin >> A >> B;
        graph[A][B] = 1;
    }

    for (int i = 1; i <= N; i++) {
        bfs(graph, rel, i);
    }

    for (int i = 1; i <= N; i++) cout << rel[i] << '\n';
}