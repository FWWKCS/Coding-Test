#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    cin.ignore();
    string line;
    for (int i = 0; i < N; i++) {
        int R, C; cin >> R >> C;
        vector<vector<int>> grid;

        for (int r = 0; r < R; r++) {
            vector<int> line;
            int x;
            for (int c = 0; c < C; c++) {
                cin >> x;
                line.push_back(x);
            }
            grid.push_back(line);
        }

        // calculate
        int total = 0;
        // 각 열의 1을 발견
        for (int c = 0; c < C; c++) {
            int block = 0;
            int top = R;
            bool found = true;
            while (true) {
                // top부터 오르면서 1탐색
                int pos = top-1;
                while (true) {
                    if (pos < 0) {
                        found = false;
                        break;
                    }
                    else if (grid[pos][c] == 1) break;

                    pos--;
                }

                if (!found) break;

                total += (top-1) - pos;

                grid[pos][c] = 0;
                grid[top-1][c] = 1;
                
                top--;
            }
        }

        cout << total << '\n';
    }
}