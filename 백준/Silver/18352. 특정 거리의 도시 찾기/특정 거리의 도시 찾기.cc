#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void bfs(vector<vector<int>> &graph, vector<int> &d, int start) {
    queue<int> q;
    q.push(start);
    
    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (auto v : graph[top]) {
            if (d[v] < INT_MAX) continue;

            q.push(v);
            d[v] = min(d[top] + 1, d[v]);
        }
    }
}

int main() {
    FASTIO;

    int N, M, K, X; cin >> N >> M >> K >> X;
    vector<vector<int>> graph(N+1);

    for (int i = 0; i < M; i++) {
        int A, B; cin >> A >> B;
        graph[A].push_back(B);
    }

    vector<int> d(N+1, INT_MAX);
    d[X] = 0;
    bfs(graph, d, X);

    bool found = false;
    for (int i = 1; i <= N; i++) {
        if (d[i] == K) {
            cout << i << '\n';
            found = true;
        }
    }

    if (!found) cout << -1;
}