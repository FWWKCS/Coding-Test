#include <iostream>
using namespace std;

int board[2][9];

int main() {
    bool isWin = false;
    int gemini = 0, startlink = 0;
    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 9; c++) cin >> board[r][c];
    }

    for (int i = 0; i < 9; i++) {
        gemini += board[0][i];
        if (gemini > startlink) isWin = true;
        startlink += board[1][i];
    }

    if (isWin) cout << "Yes";
    else cout << "No";
}