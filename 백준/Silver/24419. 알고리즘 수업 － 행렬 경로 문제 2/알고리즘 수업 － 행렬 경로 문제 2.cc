#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MOD 1'000'000'007
using namespace std;

int m[1000][1000];

int main() {
    FASTIO;
    int N; cin >> N;
    vector<vector<int>> count(N, vector<int>(N, 1));

    for (int i = 1; i < N; i++) {
        count[0][i] += count[0][i-1];
        count[i][0] += count[i-1][0];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x; cin >> x;
            m[i][j] = x;
            
            if (i >= 1 && j >= 1) {
                count[i][j] = (count[i-1][j] + count[i][j-1] + 1) % MOD;
            }
        }
    }

    cout << count[N-1][N-1] + 1 << ' ' << N * N;
}