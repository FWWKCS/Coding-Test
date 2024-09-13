#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <math.h>
#define MAX 1'000'000'009
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N, W;
double M;

void dijkstra(vector<vector<double>> &graph, vector<double> &L) {
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
    q.push(make_pair(0, 1)); // 시작점은 1
    L[1] = 0;

    while (!q.empty()) {
        double d = q.top().first;
        int v = q.top().second;
        q.pop();

        for (int c = 1; c <= N; c++) {
            if (c == v) continue;

            if (L[c] > L[v] + graph[v][c]) {
                L[c] = L[v] + graph[v][c];
                q.push(make_pair(L[c], c));
            }
        }
    }
}

double dist(pair<int, int> I, pair<int, int> J) {
    return sqrt(pow(I.first-J.first, 2) + pow(I.second-J.second, 2));
}

int main() {
    FASTIO;

    cin >> N >> W >> M;

    vector<pair<int, int>> pos = {{-MAX, -MAX}};
    for (int i = 0; i < N; i++) {
        int X, Y; cin >> X >> Y;
        pos.push_back(make_pair(X, Y));
    }

    vector<vector<double>> graph(N+1, vector<double>(N+1, MAX));
    for (int i = 1; i < N; i++) {
        for (int j = i+1; j <= N; j++) {
            double d = dist(pos[i], pos[j]);
            if (M < d) continue;
            graph[i][j] = d;
            graph[j][i] = d;
        }
    }

    for (int i = 0; i < W; i++) {
        int P, Q; cin >> P >> Q;
        graph[P][Q] = 0;
        graph[Q][P] = 0;
    }

    vector<double> L(N+1, MAX);
    dijkstra(graph, L);

    cout << int(1000 * L[N]);
}