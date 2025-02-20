#include <iostream>
#include <vector>
#include <queue>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int N;

int level = 2;
int eat = 0;
int answer = 0;

int tR = 1e9, tC = 1e9, tD = 1e9;
int sR, sC;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

vector<vector<int>> field;

bool bfs() {
    bool found = false;
    
    vector<vector<int>> visited(N, vector<int>(N, 0));
    queue<vector<int>> q;
    q.push({sR, sC, 0});
    visited[sR][sC] = 1;

    while (!q.empty()) {
        vector<int> cur = q.front();
        int cR = cur[0], cC = cur[1], d = cur[2];
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nR = cR + dr[i], nC = cC + dc[i];
            if (nR > -1 && nR < N && nC > -1 && nC < N && !visited[nR][nC] && field[nR][nC] <= level) {
                visited[nR][nC] = 1;
                if (field[nR][nC] > 0 && field[nR][nC] < level) {
                    found = true;
                    // 먹으러 갈 위치를 우선순위에 따라 저장
                    if (d+1 < tD) { tR = nR; tC = nC; tD = d+1; } // 거리순 
                    else if (d+1 == tD) {
                        if (nR < tR) { tR = nR; tC = nC; } // 위에 있는 순
                        else if (nR == tR) {
                            if (nC < tC) { tC = nC; } // 왼쪽에 있는 순
                        } 
                    }
                }

                q.push({nR, nC, d+1});
            }
        }
    }

    return found;
}

int main() {
    FASTIO;

    cin >> N;
    field.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> field[i][j];
            if (field[i][j] == 9) {
                sR = i; sC = j;
                field[sR][sC] = 0;
            }
        }
    }

    while (bfs()) {
        // 이동 후 상태 업데이트
        answer += tD;
        eat++;
        if (eat == level) {
            level++;
            eat = 0;
        }

        sR = tR; sC = tC;
        field[sR][sC] = 0;
        tR = 1e9; tC = 1e9; tD = 1e9;
    }

    cout << answer;
}