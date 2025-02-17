#include <iostream>
#include <queue>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N, M;
int total = 0;
int answer = 0;
vector<vector<int>> field;
vector<pair<int, int>> viruses;
vector<pair<int, int>> target;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void bfs() {
    vector<vector<int>> visited(N, vector<int>(M, 0));
    queue<pair<int, int>> q;
    for (auto &[r, c] : viruses) {
        q.push({r, c});
        visited[r][c] = 1;
    }

    int move = 0;

    while (!q.empty()) {
        auto &[cR, cC] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nR = cR + dr[i], nC = cC + dc[i];
            if (nR > -1 && nR < N && nC > -1 && nC < M && !visited[nR][nC] && !field[nR][nC]) {
                q.push({nR, nC});
                visited[nR][nC] = 1;
                move++;
            }   
        }
    }
    
    answer = max(answer, total-move);
}

void recursion(int depth, int start) {
    if (depth == 3) {
        bfs();
        return;
    }

    for (int i = start; i < N * M; i++) {
        int r = i / M, c = i % M; // 2D 좌표 변환
        if (!field[r][c]) {
            field[r][c] = 1;
            total--;
            recursion(depth + 1, i + 1);
            field[r][c] = 0;
            total++;
        }
    }
}

int main() {
    FASTIO;

    cin >> N >> M;
    field.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> field[i][j];
            if (!field[i][j]) total++;
            if (field[i][j] == 2) viruses.push_back({i, j});
        }
    }

    recursion(0, 0);

    cout << answer;
}