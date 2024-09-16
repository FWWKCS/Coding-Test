#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int n, k; cin >> n >> k;
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));

    while (k--) {
        int p, q; cin >> p >> q;
        graph[p][q] = 1;
    }

    for (int i = 1; i <= n; i++) graph[i][i] = 1;

    for (int m = 1; m <= n; m++) {
        for (int P = 1; P <= n; P++) {
            for (int Q = 1; Q <= n; Q++) {
                if (graph[P][m] && graph[m][Q]) graph[P][Q] = 1;
            }
        }
    }

    int s; cin >> s;
    while (s--) {
        int x, y; cin >> x >> y;

        if (graph[x][y]) cout << -1 << '\n';
        else if (graph[y][x]) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}