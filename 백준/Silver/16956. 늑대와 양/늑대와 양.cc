#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int R, C; cin >> R >> C;
    vector<vector<char>> field(R, vector<char>(C));

    for (int i = 0; i < R; i++) {
        string s; cin >> s;
        for (int j = 0; j < C; j++) {
            field[i][j] = s[j];
        }
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (field[r][c] == 'S') {
                if ((r > 0 && field[r-1][c] == 'W')
                 || (r < R-1 && field[r+1][c] == 'W')
                 || (c > 0 && field[r][c-1] == 'W')
                 || (c < C-1 && field[r][c+1] == 'W')) {
                    cout << 0 << '\n';
                    return 0;
                 }
                else {
                    if (r > 0 && field[r-1][c] == '.') field[r-1][c] = 'D';
                    if (r < R-1 && field[r+1][c] == '.') field[r+1][c] = 'D';
                    if (c > 0 && field[r][c-1] == '.') field[r][c-1] = 'D';
                    if (c < C-1 && field[r][c+1] == '.') field[r][c+1] = 'D';                
                }
            }
        }
    }

    cout << 1 << '\n';
    for (auto v : field) {
        for (auto c : v) cout << c;
        cout << '\n';
    }
}