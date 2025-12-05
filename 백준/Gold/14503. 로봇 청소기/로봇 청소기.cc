#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int N, M;
vector<vector<int>> board;

int r, c, d;

int answer = 0;

int rotate() {
    switch (d) {
        case 0: return 3;
        case 1: return 0;
        case 2: return 1;
        case 3: return 2;
    }

    return -1;
}

int update() {
    if (board[r][c] == 0) {
        // 청소
        answer++;
        board[r][c] = 2;
        // cout << "cur pos: " << r << ' ' << c << '\n';
    }

    if (board[r-1][c] != 0 
        && board[r+1][c] != 0 
        && board[r][c-1] != 0 
        && board[r][c+1] != 0) { // 4방향 모두 청소됨
        // 후진
        switch (d) {
            case 0: { // 북
                if (board[r+1][c] == 1) return -1;
                else r++;
                break;
            }
            case 1: { // 동
                if (board[r][c-1] == 1) return -1;
                else c--;
                break;
            }
            case 2: { // 남
                if (board[r-1][c] == 1) return -1;
                else r--;
                break;
            }
            case 3: { // 서
                if (board[r][c+1] == 1) return -1;
                else c++;
                break;
            }
        }
    }
    else {
        bool found = false;
        while (!found) {
            // 반시계 회전
            d = rotate();
            
            // cout << "cur dir: " << d << ' ' << r << ' ' << c << '\n';

            // 전방 검사 및 전진
            switch (d) {
                case 0: { // 북
                    if (board[r-1][c] == 0) {
                        found = true;
                        r--;
                    }
                    break;
                }
                case 1: { // 동
                    if (board[r][c+1] == 0) {
                        found = true;
                        c++;
                    }
                    break;
                }
                case 2: { // 남
                    if (board[r+1][c] == 0) {
                        found = true;
                        r++;
                    }
                    break;
                }
                case 3: { // 서
                    if (board[r][c-1] == 0) {
                        found = true;
                        c--;
                    }
                    break;
                }
            }
        }
    }

    return 1;
}

int main() {
    FASTIO;

    cin >> N >> M;
    board.resize(N, vector<int>(M));
    
    cin >> r >> c >> d;
    // 0: 북, 1: 동, 2: 남, 3: 서

    for (auto &y : board) {
        for (auto &x : y) cin >> x;
    }
    
    while (true) {
        int result = update();
        if (result == -1) break; 
    }

    cout << answer;
}