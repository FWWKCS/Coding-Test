#include <iostream>
#include <vector>
#define MAX 1e9
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N, K; cin >> N >> K;

    vector<vector<int>> graph(N+1, vector<int>(N+1, MAX));
    while (K--) {
        int A, B; cin >> A >> B;
        graph[A][B] = graph[B][A] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int P = 1; P <= N; P++) {
            for (int Q = 1; Q <= N; Q++) {
                graph[P][Q] = min(graph[P][Q], graph[P][k] + graph[k][Q]);
            }
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (graph[r][c] > 6) {
                cout << "Big World!";
                return 0;
            }            
        }
    }

    cout << "Small World!";
}