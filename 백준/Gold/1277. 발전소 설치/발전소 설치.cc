#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <math.h>
#define MAX 1'000'000'009
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void dijkstra(vector<vector<pair<int, long double>>> &graph, vector<int> &route, vector<long double> &L) {
    // 1에서 시작
    L[1] = 0;
    priority_queue<pair<long double, int>, vector<pair<long double, int>>, greater<pair<long double, int>>> q;
    q.push(make_pair(0, 1));

    while (!q.empty()) {
        long double d = q.top().first;
        int v = q.top().second;
        q.pop();

        for (auto x : graph[v]) {
            if (d + x.second < L[x.first]) {
                L[x.first] = d + x.second;
                route[v] = x.first;
                q.push(make_pair(L[x.first], x.first));
            }
        }
    }
}


long double dist(pair<int, int> I, pair<int, int> J) {
    return sqrt(pow(I.first-J.first, 2) + pow(I.second-J.second, 2));
}

int main() {
    FASTIO;

    int N, W; cin >> N >> W;
    long double M; cin >> M;

    vector<pair<int, int>> pos = {{-MAX, -MAX}};
    for (int i = 0; i < N; i++) {
        int X, Y; cin >> X >> Y;
        pos.push_back(make_pair(X, Y));
    }

    // 이미 존재하는 간선 저장
    vector<set<int>> edges(N+1);
    for (int i = 0; i < W; i++) {
        int P, Q; cin >> P >> Q;
        edges[P].insert(Q);
        edges[Q].insert(P);
    }

    // 그래프 생성
    vector<vector<pair<int, long double>>> graph(N+1);
    for (int i = 1; i < N; i++) {
        for (int j = i+1; j <= N; j++) {
            bool exist = false;
            if ((edges[i].find(j) != edges[i].end()) || (edges[j].find(i) != edges[j].end())) exist = true;

            long double d = exist ? 0 : dist(pos[i], pos[j]);
            if (M >= d) {
                graph[i].push_back(make_pair(j, d));
                graph[j].push_back(make_pair(i, d));
            }
        }
    }

    // dijkstra
    vector<int> route(N+1, -1);
    vector<long double> L(N+1, MAX);
    dijkstra(graph, route, L);

    cout << int(1000 * L[N]);
}