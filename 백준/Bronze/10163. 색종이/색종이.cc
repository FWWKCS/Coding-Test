#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    int x, y, w, h;
    vector<vector<int>> board (1001, vector<int>(1001, 0));
    for (int k = 1; k <= N; k++) {
        cin >> x >> y >> w >> h;
        for (int r = 0; r < h; r++) {
            for (int c = 0; c < w; c++) {
                board[y+r][x+c] = k;
            }
        }
    }

    vector<int> count(N+1, 0);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] > 0) count[board[i][j]]++;
        }
    }

    for (int k = 1; k <= N; k++) cout << count[k] << '\n';
}