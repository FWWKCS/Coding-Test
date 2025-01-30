#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

char space[50][50];
int answer[5] = {0, };

int check(int r, int c) {
    int count = 0; 
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (space[r+i][c+j] == '#') return -1;

            if (space[r+i][c+j] == 'X') count++;
        }
    }

    return count;
}

int main() {
    FASTIO;

    int R, C; cin >> R >> C;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            char x; cin >> x;
            space[r][c] = x;
        }
    }

    for (int r = 0; r < R-1; r++) {
        for (int c = 0; c < C-1; c++) {
            int idx = check(r, c);
            if (idx != -1) answer[idx]++;
        }
    }

    for (int x : answer) cout << x << '\n';
}