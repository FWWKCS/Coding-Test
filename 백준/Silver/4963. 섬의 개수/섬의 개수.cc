#include <iostream>
#include <vector>
#include <queue>
#define MAX 50
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int table[MAX][MAX];

void bfs(int w, int h, int r, int c, vector<vector<int>> &visited) {
    queue<pair<int, int>> q;
    q.push(make_pair(r, c));
    visited[r][c] = 1;

    int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int dr = y + dy[i];
            int dc = x + dx[i];

            if (dr > -1 && dr < h && dc > -1 && dc < w && table[dr][dc] && !visited[dr][dc]) {
                visited[dr][dc] = 1;
                q.push(make_pair(dr, dc));
            }
        } 
    }

}

int main() {   
    FASTIO;

    int w, h;
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) return 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int x; cin >> x;
                table[i][j] = x;
            }
        }

        int total = 0;
        vector<vector<int>> visited(h, vector<int>(w, 0));
        for (int r = 0; r < h; r++) {
            for (int c = 0; c < w; c++) {
                if (table[r][c] && !visited[r][c]) {
                    bfs(w, h, r, c, visited);
                    total++;
                }
            }
        }

        cout << total << '\n';
    }
}