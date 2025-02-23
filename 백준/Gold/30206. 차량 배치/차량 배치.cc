#include <iostream>
#include <vector>
#include <queue>
#define MAX 200'000
#define MOD 1'000'000'007
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;

int N, M;
vector<int> graph[MAX+1];
vector<int> level(MAX, 0);
ll answer = 2;

void bfs() {
    vector<int> dist(N+1, -1);
    dist[1] = 0;

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (dist[next] == -1) {
                q.push(next);
                dist[next] = dist[cur] + 1;
                level[dist[next]]++;
            }
        }
    }
}

int main() {
    FASTIO;

    cin >> N >> M;
    while (M--) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs();

    for (auto l : level) {
        answer = (answer * (l + 1)) % MOD;
    }

    cout << answer - 1;
}