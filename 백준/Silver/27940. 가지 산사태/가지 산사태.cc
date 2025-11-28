#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main() {
    FASTIO;
    
    int N, M, K; cin >> N >> M >> K;
    int S = 0;
    for (int p = 1; p <= M; p++) {
        int t, r; cin >> t >> r;
        S += r;
        if (S > K) {
            cout << p << ' ' << 1;
            return 0;
        }
    }

    cout << -1;
    return 0;
}