#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int R, C, T;
int up = -1, down = -1;
vector<vector<int>> field;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void spread(vector<vector<int>>& delta) {
    // 퍼질 위치 탐색
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (field[r][c] > 0) {
                int spr = 0;
                for (int i = 0; i < 4; i++) {
                    int nR = r + dr[i], nC = c + dc[i];
                    if (nR > 0 && nR <= R && nC > 0 && nC <= C && field[nR][nC] != -1) {
                        delta[nR][nC] += field[r][c] / 5;
                        spr++;
                    }
                }

            delta[r][c] -= (field[r][c] / 5) * spr;
            }
        }
    }

    // 순회후 필드에 합산
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            field[r][c] += delta[r][c];
        }
    }
}

void move() {
    // 윗방향 청정기 직전부터 순회
    for (int r = up-1; r > 1; r--) 
        field[r][1] = field[r-1][1];
    
    for (int c = 1; c < C; c++) 
        field[1][c] = field[1][c+1];

    for (int r = 1; r < up; r++)   
        field[r][C] = field[r+1][C];

    for (int c = C; c > 2; c--) 
        field[up][c] = field[up][c-1];

    field[up][2] = 0;

    // 아랫방향 청정기 직전부터 순회
    for (int r = down+1; r < R; r++)   
        field[r][1] = field[r+1][1];

    for (int c = 1; c < C; c++) 
        field[R][c] = field[R][c+1];

    for (int r = R; r > down; r--) 
        field[r][C] = field[r-1][C];

    for (int c = C; c > 2; c--) 
        field[down][c] = field[down][c-1];

    field[down][2] = 0;
}

int main() {
    FASTIO;

    cin >> R >> C >> T;
    field.resize(R+1, vector<int>(C+1));
    
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> field[r][c];
            if (field[r][c] == -1) {
                if (up == -1) up = r;
                else down = r;
            } 
        }
    }
    
    while (T--) {
        vector<vector<int>> delta(R+1, vector<int>(C+1, 0));

        // 확산
        spread(delta);

        // 이동
        move();
    }

    int total = 0;
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            total += max(0, field[r][c]);
        }
    }

    cout << total;
}