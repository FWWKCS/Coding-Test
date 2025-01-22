#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;
    int N, M; cin >> N >> M;

    int cost[N+M+1] = {0};
    for (int i = 1; i <= N; i++) {
        int S; cin >> S;
        cost[i] = S;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N+M; j++) {
            int T; cin >> T; 
            cost[i] -= T;
            cost[j] += T;
        }
    }

    for (int i = 1; i <= N+M; i++) cout << cost[i] << ' ';
}