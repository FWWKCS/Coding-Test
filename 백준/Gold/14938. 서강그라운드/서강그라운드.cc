#include <iostream>
#include <vector>
#include <queue>
#define MAX 1'000'000
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &graph, vector<vector<int>> &dist, int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, start));

    while (!q.empty()) {
        int d = q.top().first, v = q.top().second;
        q.pop();

        for (auto x : graph[v]) {
            if (dist[start][x.first] > dist[start][v] + x.second) {
                dist[start][x.first] = dist[start][v] + x.second;
                q.push(make_pair(dist[start][v] + x.second, x.first));
            }
        }
    }
}

int main() {
    FASTIO;

    int n, m, r; cin >> n >> m >> r;
    int items[n+1] = {0, };
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        items[i] = t;
    }

    vector<vector<pair<int, int>>> graph(n+1);
    for (int i = 0; i < r; i++) {
        int a, b, l; cin >> a >> b >> l;
        graph[a].push_back(make_pair(b, l));
        graph[b].push_back(make_pair(a, l));
    }

    vector<vector<int>> dist(n+1, vector<int>(n+1, MAX));
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
        dijkstra(graph, dist, i);

        int tmp = 0;
        for (int k = 1; k <= n; k++) {
            if (dist[i][k] <= m) tmp += items[k]; 
        }

        answer = max(answer, tmp);
    }

    cout << answer;
}