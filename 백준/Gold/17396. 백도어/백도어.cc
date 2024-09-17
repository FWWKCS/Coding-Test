#include <iostream>
#include <queue>
#include <vector>
#define MAX 1e12
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &graph, vector<long long> &dist) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q; // (D1, Q1), (D2, Q2), ... 
    dist[0] = 0;
    q.push(make_pair(0, 0));

    while (!q.empty()) {
        long long l = q.top().first;
        int v = q.top().second;
        q.pop();

        if (l > dist[v]) continue; // TLE 처리

        for (auto x : graph[v]) {
            if (dist[x.first] > dist[v] + x.second) {
                dist[x.first] = dist[v] + x.second;
                q.push(make_pair(dist[x.first], x.first));
            }
        }
    }
}

int main() {
    FASTIO;

    int N, M; cin >> N >> M;
    vector<int> sight(N, 0);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        sight[i] = x;
    }

    vector<vector<pair<int, int>>> graph(N); // P : (Q1, T1), (Q2, T2), ..
    while (M--) {
        int a, b, t; cin >> a >> b >> t;
        if ((a != N-1 && b != N-1) && (sight[a] || sight[b])) continue;
        graph[a].push_back(make_pair(b, t)); 
        graph[b].push_back(make_pair(a, t));
    }

    vector<long long> dist(N, MAX);
    dijkstra(graph, dist);

    if (dist[N-1] >= MAX) cout << -1;
    else cout << dist[N-1];
}