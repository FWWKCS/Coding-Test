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
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    visited[y][x] = true;

    int length = 0;
    queue<vector<int>> q;
    vector<int> e = {y, x, 1};
    q.push(e);

    int r, c, l, t;
    while (!q.empty()) {
        vector<int> getter = q.front();
        r = getter[0];
        c = getter[1];
        l = getter[2];

        q.pop();

        if (l > maxL) {
            maxL = l;
            answer = map[y][x] + map[r][c];
        }
        else if (l == maxL) answer = max(answer, map[y][x] + map[r][c]);

        int dr, dc;
        for (int i = 0; i < 4; i++) {
            dr = r+dy[i];
            dc = c+dx[i];
            
            if (-1 < dr && dr < N && -1 < dc && dc < M && !visited[dr][dc] && map[dr][dc] != 0) {
                visited[dr][dc] = true;
                q.push({dr, dc, l+1});
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