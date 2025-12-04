#include <iostream>
#include <vector>
using namespace std;

int N, M, x, y, K;
vector<vector<int>> board;

int u = 0, e = 0, w = 0, s = 0, n = 0, d = 0;

int update(int dir) {
    // cout << dir << '\n';
    switch (dir) {
        case 1: { // 동쪽
            if (x < M-1) {
                // 이동
                x++;
                
                // 회전
                int tmp = w;
                // w <- d
                // d <- e
                // e <- u
                // u <- w
                w = d;
                d = e;
                e = u;
                u = tmp;

                // cout << u << ' ' << d << '\n';
            }
            else return -1;
            break;
        }
        case 2: { // 서쪽
            if (x > 0) {
                // 이동
                x--;

                // 회전
                int tmp = u;
                // u <- e
                // e <- d
                // d <- w
                // w <- u
                u = e;
                e = d;
                d = w;
                w = tmp;

                // cout << u << ' ' << d << '\n';
            }
            else return -1;
            break;
        }
        case 3: { // 북쪽
            if (y > 0) {
                // 이동
                y--;

                // 회전
                int tmp = u;
                // u <- s
                // s <- d
                // d <- n
                // n <- u
                u = s;
                s = d;
                d = n;
                n = tmp;
                
                // cout << u << ' ' << d << '\n';
            }
            else return -1;
            break;
        }
        case 4: { // 남쪽
            if (y < N-1) {
                // 이동
                y++;

                // 회전
                int tmp = n;
                // n <- d
                // d <- s
                // s <- u
                // u <- n
                n = d;
                d = s;
                s = u;
                u = tmp;

                // cout << u << ' ' << d << '\n';
            }
            else return -1;
            break;
        }
    }

    // 변화
    if (board[y][x] != 0) {
        // 주사위 d 변경
        d = board[y][x];
        board[y][x] = 0;
    }
    else board[y][x] = d;

    return 1;
}

int main() {
    cin >> N >> M >> y >> x >> K;
    board.resize(N, vector<int>(M, 0));

    for (auto &r : board) {
        for (auto &c : r) cin >> c;
    }

    while (K--) {
        int dir; cin >> dir;
        int result = update(dir);
        if (result > 0) cout << u << '\n';
    }
}