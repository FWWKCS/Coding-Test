#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> board(101, vector<int>(101, 0));
    for (int k = 0; k < 4; k++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int r = y1; r < y2; r++) {
            for (int c = x1; c < x2; c++) 
                board[r][c] = 1;
        }

    }

    int count = 0;
    for (int r = 0; r < board.size(); r++) {
        for (int c = 0; c < board[r].size(); c++) 
            if (board[r][c] == 1) count++;
    }

    cout << count;
}