#include <iostream>
#define MAX 1000
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int store[MAX+1][MAX+1] = {0, };
int memoization[MAX+1][MAX+1] = {0, };
int last[MAX+1][MAX+1] = {0, };

int main() {
    FASTIO;

    int N; cin >> N;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            int x; cin >> x;
            store[r][c] = x;
        }
    }
    
    if (store[1][1] == 0) memoization[1][1] = 1;
    else last[1][1] = 2;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (r == 1 && c == 1) continue;

            if (r == 1) {
                if (store[r][c] == (last[r][c-1] + 1) % 3) {
                    memoization[r][c] = memoization[r][c-1] + 1;
                    last[r][c] = (last[r][c-1] + 1) % 3;
                }
                else {
                    memoization[r][c] = memoization[r][c-1];
                    last[r][c] = last[r][c-1];
                }
            }
            else if (c == 1) {
                if (store[r][c] == (last[r-1][c] + 1) % 3) {
                    memoization[r][c] = memoization[r-1][c] + 1;
                    last[r][c] = (last[r-1][c] + 1) % 3;
                }
                else {
                    memoization[r][c] = memoization[r-1][c];
                    last[r][c] = last[r-1][c];
                }
            }
            else {
                int D = memoization[r-1][c];
                if (store[r][c] == (last[r-1][c] + 1) % 3) D++;

                int R = memoization[r][c-1];
                if (store[r][c] == (last[r][c-1] + 1) % 3) R++;

                if (D <= R) {
                    memoization[r][c] = R;
                    if (memoization[r][c-1] != R) last[r][c] = (last[r][c-1] + 1) % 3;
                    else last[r][c] = last[r][c-1];
                }
                else {
                    memoization[r][c] = D;
                    if (memoization[r-1][c] != D) last[r][c] = (last[r-1][c] + 1) % 3;
                    else last[r][c] = last[r-1][c];
                }
            }
        }
    }

    cout << memoization[N][N];
}