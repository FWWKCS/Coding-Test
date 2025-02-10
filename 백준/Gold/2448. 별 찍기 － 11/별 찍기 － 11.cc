#include <iostream>
#include <math.h>
#define MAX 3072
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N;

int table[MAX+1][(MAX*2)+1];

void recursion(int N, int r, int c) {
    if (N == 3) {
        // 삼각형 작도
        table[r][c] = 1;
        table[r+1][c-1] = 1;
        table[r+1][c+1] = 1;
        for (int i = c-2; i <= c+2; i++) table[r+2][i] = 1;

        return;
    }

    int v = N/2;

    recursion(v, r, c);
    recursion(v, r+v, c-v);
    recursion(v, r+v, c+v);
}

int main() {
    FASTIO;

    cin >> N;

    recursion(N, 1, N);

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N*2; c++) {
            if (table[r][c]) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
}