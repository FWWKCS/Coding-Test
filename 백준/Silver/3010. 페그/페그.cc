#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

char board[7][7];

int main() {
    FASTIO;

    for (int i = 0; i < 7; i++) {
        string s; getline(cin, s);
        for (int j = 0; j < 7; j++) {
            board[i][j] = s[j];
        }
    }

    int answer = 0;
    for (int r = 0; r < 7; r++) {
        for (int c = 0; c < 7; c++) {
            if (board[r][c] == 'o') {
                if (r >= 2 && board[r-1][c] == 'o' && board[r-2][c] == '.') answer++;
                if (r <= 4 && board[r+1][c] == 'o' && board[r+2][c] == '.') answer++;
                if (c >= 2 && board[r][c-1] == 'o' && board[r][c-2] == '.') answer++;
                if (c <= 4 && board[r][c+1] == 'o' && board[r][c+2] == '.') answer++;
            } 
        }
    }

    cout << answer;
}