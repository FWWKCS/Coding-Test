#include <iostream>
#include <vector>
#define MAX 500
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N, M; cin >> N >> M;
    int graph[MAX+1][MAX+1] = {0, };
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int x; cin >> x;
            graph[i][j] = x;
        }
    }

    for (int k = 1; k <= N; k++) {
        for (int P = 1; P <= N; P++) {
            for (int Q = 1; Q <= N; Q++) {
                graph[P][Q] = min(graph[P][Q], graph[P][k]+graph[k][Q]);
            }
        }
    }

    while (M--) {
        int A, B, C; cin >> A >> B >> C;
        if (graph[A][B] <= C) cout << "Enjoy other party\n";
        else cout << "Stay here\n";
    }
}