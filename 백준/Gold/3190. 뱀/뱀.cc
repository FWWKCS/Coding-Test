#include <iostream>
#include <vector>
#include <deque>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int N;
vector<vector<int>> board;
// 1: snake 
// 2: apple

deque<pair<int, int>> snake = {{0, 0}};
// {r, c}
// idx 0: head
// idx back: tail

bool over = false; // 게임종료 플래그

void update(int r, int c) {
    // 뱀 정보 갱신 
    int head_nr = snake[0].first + r;
    int head_nc = snake[0].second + c;

    int tail_r = snake.back().first;
    int tail_c = snake.back().second;

    // 뻗은 위치 
    // 1. 벽 충돌
    if (head_nr < 0 || head_nr >= N || head_nc < 0 || head_nc >= N) {
        over = true;
        return;
    }

    // 2. 몸체 충돌
    else if (board[head_nr][head_nc] == 1) {
        over = true;
        return;
    }

    // 3. 사과
    else if (board[head_nr][head_nc] == 2) {
        // board 배열 갱신: head 위치를 1로, 꼬리 움직임X
        board[head_nr][head_nc] = 1;

        // snake 배열 갱신
        snake.push_front(make_pair(head_nr, head_nc));
    }

    // 4. 빈 공간
    else {
        // board 배열 갱신: head 위치를 1로, tail 위치를 0으로
        board[head_nr][head_nc] = 1;
        board[tail_r][tail_c] = 0;

        // snake 배열 갱신
        for (int i = snake.size()-1; i > 0; i--) {
            snake[i] = snake[i-1];
        }

        snake[0] = make_pair(head_nr, head_nc);
    }
}


int main() {
    FASTIO;

    cin >> N;
    board.resize(N, vector<int>(N, 0));
    board[0][0] = 1;

    int K; cin >> K;
    while (K--) {
        int r, c; cin >> r >> c;
        board[r-1][c-1] = 2;
    }

    vector<char> transfer(11'000, 'X');
    // L: 시선방향의 왼쪽
    // D: 시선방향의 오른쪽
    int L; cin >> L;
    while (L--) {
        int X; char C; cin >> X >> C;
        transfer[X] = C;
    }

    char dir = 'E';
    int t = 0;
    while (true) {
        // 이동
        t++;
        switch (dir) {
            case 'E': { // 동쪽
                update(0, 1);
                break;
            }
            case 'W': { // 서쪽
                update(0, -1);
                break;
            }
            case 'S': { // 남쪽
                update(1, 0);
                break;
            }
            case 'N': { // 북쪽
                update(-1, 0);
                break;
            }
        }

        if (over) break; // 게임종료

        
        // 방향 전환
        if (transfer[t] == 'X') continue;

        switch (dir) { 
            case 'E': { // 동쪽
                dir = transfer[t] == 'L' ? 'N' : 'S';
                break;
            }
            case 'W': { // 서쪽
                dir = transfer[t] == 'L' ? 'S' : 'N';
                break;
            }
            case 'S': { // 남쪽
                dir = transfer[t] == 'L' ? 'E' : 'W';
                break;
            }
            case 'N': { // 북쪽
                dir = transfer[t] == 'L' ? 'W' : 'E';
                break;
            }
        }
    }

    cout << t;
    return 0;
}