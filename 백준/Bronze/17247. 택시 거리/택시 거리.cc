#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N, M; cin >> N >> M;

    int table[N][M];

    int x1 = -1, y1 = -1, x2, y2;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            int x; cin >> x;
            table[r][c] = x;

            if (x1 == -1 && y1 == -1 && x == 1) { y1 = r; x1 = c; }
            else if (x == 1) { y2 = r; x2 = c; }
        }
    }

    cout << abs(y2-y1)+abs(x2-x1);
}