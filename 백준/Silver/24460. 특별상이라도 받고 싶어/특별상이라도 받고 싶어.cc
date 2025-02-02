#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int table[1024][1024];

int rec(int r, int c, int N) {
    if (N == 1) {
        return table[r][c];
    }

    vector<int> value = {
        rec(r, c, N/2),
        rec(r, c+N/2, N/2),
        rec(r+N/2, c, N/2),
        rec(r+N/2, c+N/2, N/2)
    };

    sort(value.begin(), value.end());
    return value[1];
}

int main() {
    FASTIO;

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x; cin >> x;
            table[i][j] = x;
        }
    }

    cout << rec(0, 0, N);
}