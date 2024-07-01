#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int N, M;
int maxL = 0, answer = 0;

// U, D, L, R
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

void bfs(int y, int x, vector<vector<int>> &map) {
    vector<vector<int>> visited(N, vector<int>(M, 0));
    visited[y][x] = 1;

    int length = 0;
    queue<pair<int, int>> q;
    q.push({y, x});

    int r, c, l, t;
    while (!q.empty()) {
        tie(r, c) = q.front();
        q.pop();

        if (visited[r][c] > maxL) {
            maxL = visited[r][c];
            answer = map[y][x] + map[r][c];
        }
        else if (visited[r][c] == maxL) answer = max(answer, map[y][x] + map[r][c]);

        int dr, dc;
        for (int i = 0; i < 4; i++) {
            dr = r+dy[i];
            dc = c+dx[i];
            
            if (-1 < dr && dr < N && -1 < dc && dc < M && visited[dr][dc] == 0 && map[dr][dc] != 0) {
                visited[dr][dc] = visited[r][c] + 1;
                q.push({dr, dc});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M, 0));
    int x;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> x;
            map[r][c] = x;
        }
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (map[r][c] != 0) bfs(r, c, map);
        }
    }
    cout << answer;
}