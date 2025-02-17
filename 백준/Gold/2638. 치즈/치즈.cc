#include <iostream>
#include <vector>
#include <queue>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N, M;
vector<vector<int>> field;
vector<pair<int, int>> target;
vector<pair<int, int>> filtered;
int answer = 0;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool bfs() {
    bool melted = false;

    vector<vector<int>> visited(N, vector<int>(M, 0));
    queue<pair<int, int>> q;
    // {0, 0} 에서 순회하며 제거할 1을 탐색
    q.push({0, 0});
    visited[0][0] = 1;

    while (!q.empty()) {
        auto &[cR, cC] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nR = cR + dr[i], nC = cC + dc[i];
            if (nR > -1 && nR < N && nC > -1 && nC < M && !visited[nR][nC]) {
                if (field[nR][nC]) {
                    // 체크할 치즈로 저장
                    visited[nR][nC] = 1;
                    target.push_back({nR, nC});
                } 
                else {
                    q.push({nR, nC});
                    visited[nR][nC] = 1;
                }
            }
        }
    }

    // 찾은 대상이 제거할 수 있는지 체크
    for (auto &[r, c] : target) {
        int total = 0;
        for (int i = 0; i < 4; i++) {
            int nR = r + dr[i], nC = c + dc[i];
            if (!field[nR][nC] && visited[nR][nC]) total++;
        }

        if (total >= 2) {
            melted = true;
            filtered.push_back({r, c});
        }      
    } 

    // 확정된 치즈칸 제거
    for (auto &[r, c] : filtered) 
        field[r][c] = 0;

    return melted;
}

int main() {
    cin >> N >> M;
    field.resize(N, vector<int>(M));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) cin >> field[r][c];
    }

    while (bfs()) {
        target.clear();
        filtered.clear();
        answer++;
    }
    cout << answer;
}