#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    while (true) {
        int R, C; cin >> R >> C;
        if (R == 0 && C == 0) break;
        
        vector<string> board;
        for (int i = 0; i < R; i++) {
            string line; cin >> line;
            board.push_back(line);
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] == '.') {
                    int count = 0;
                    if (i > 0) { // 위쪽 검사
                        if (j > 0 && board[i-1][j-1] == '*') count++;
                        if (board[i-1][j] == '*') count++;
                        if (j < C-1 && board[i-1][j+1] == '*') count++;
                    }

                    if (j > 0 && board[i][j-1] == '*') count++;
                    if (j < C-1 && board[i][j+1] == '*') count++;

                    if (i < R-1) { // 아래쪽 검사
                        if (j > 0 && board[i+1][j-1] == '*') count++;
                        if (board[i+1][j] == '*') count++;
                        if (j < C-1 && board[i+1][j+1] == '*') count++;
                    }

                    cout << count;
                }
                else cout << '*';
            }
            cout << '\n';
        }
    }
}