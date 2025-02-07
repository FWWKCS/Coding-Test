#include <iostream>
#include <queue>
#include <vector>
#include <map>
#define INF 1e9
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N, M;
map<int, vector<pair<int, int>>> graph;

int dijkstra(int X, int Y) {
    vector<int> dist(N+1, INF);
    dist[X] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push(make_pair(0, X));

    while (!q.empty()) {
        int d = q.top().first, cur = q.top().second;
        q.pop();

        if (d > dist[cur]) continue; // 이미 최단 경로가 확정된 경우

        for (auto &[next, cost] : graph[cur]) {
            if (d + cost < dist[next]) {
                dist[next] = d + cost;
                q.push(make_pair(dist[next], next));
            }
        }
    }

    return dist[Y];
}

int main() {
    FASTIO;

    cin >> N >> M;
    while (M--) {
        int x, y, c; cin >> x >> y >> c;
        graph[x].push_back(make_pair(y, c));
    }

    int start, end; cin >> start >> end;
    cout << dijkstra(start, end);
}