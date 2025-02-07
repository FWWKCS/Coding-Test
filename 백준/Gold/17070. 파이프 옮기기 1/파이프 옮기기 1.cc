#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N;
int board[17][17];

int answer = 0;

void recursion(int mode, int r, int c) {
    if (r == N && c == N) {
        answer++;
        return;
    }

    // 가로
    if (mode == 0 || mode == 2) {
        if (c < N && board[r][c+1] != 1) 
            recursion(0, r, c+1);
    }
    // 세로
    if (mode == 1 || mode == 2) {
        if (r < N && board[r+1][c] != 1) 
            recursion(1, r+1, c);
    }
    // 대각선
    if (r < N && c < N && board[r][c+1] != 1 && board[r+1][c] != 1 && board[r+1][c+1] != 1) 
        recursion(2, r+1, c+1);
}


int main() {
    FASTIO;

    cin >> N;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> board[r][c];
        }
    }

    // board[1][1] = 1, board[1][2] = 1;
    int mode = 0; // 0: 가로, 1: 세로, 2: 대각선

    recursion(mode, 1, 2);

    cout << answer;
}