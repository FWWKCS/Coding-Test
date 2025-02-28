#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N;
vector<vector<char>> table;
vector<pair<int, int>> tPos, xPos;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool check() {
    for (auto t : tPos) {
        // 4방향 검사
        for (int i = 0; i < 4; i++) {
            int r = t.first, c = t.second;
            while (r > -1 && r < N && c > -1 && c < N) {
                if (table[r][c] == 'O') break;
                else if (table[r][c] == 'S') return false;

                r += dr[i], c += dc[i];
            }
        }
    }

    return true;
}

int main() {
    cin >> N;
    table.resize(N, vector<char>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> table[i][j];
            if (table[i][j] == 'T') tPos.push_back({i, j});
            else if (table[i][j] == 'X') xPos.push_back({i, j});
        }
    }

    for (int i = 0; i < xPos.size()-2; i++) {
        table[xPos[i].first][xPos[i].second] = 'O';
        for (int j = i+1; j < xPos.size()-1; j++) {
            table[xPos[j].first][xPos[j].second] = 'O';
            for (int k = j+1; k < xPos.size(); k++) {
                table[xPos[k].first][xPos[k].second] = 'O';

                if (check()) {
                    cout << "YES";
                    return 0;
                }

                table[xPos[k].first][xPos[k].second] = 'X';
            }
            table[xPos[j].first][xPos[j].second] = 'X';
        }
        table[xPos[i].first][xPos[i].second] = 'X';
    }

    cout << "NO";
}