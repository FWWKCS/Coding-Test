#include <iostream>
#include <vector>
#define MAX 1'000'000'007
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>(n+1, MAX));
    vector<vector<int>> route(n+1, vector<int>(n+1, -1));
    for (int i = 0; i < m; i++) {
        int a, b, l; cin >> a >> b >> l;
        graph[a][b] = l;
        graph[b][a] = l;

        route[a][b] = b;
        route[b][a] = a;
    }

    for (int k = 1; k <= n; k++) {
        for (int P = 1; P <= n; P++) {
            for (int Q = 1; Q <= n; Q++) {
                if (P == Q) continue;

                if (graph[P][Q] > graph[P][k]+graph[k][Q]) {
                    graph[P][Q] = graph[P][k]+graph[k][Q];
                    route[P][Q] = route[P][k];
                }
            }
        }
    }

    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            if (route[r][c] == -1) cout << "- ";
            else cout << route[r][c] << ' ';
        }
        cout << '\n';
    }
}