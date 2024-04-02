#include <bits/stdc++.h>
using namespace std;

int countBingo(vector<vector<int>>& board) {
    int bingo = 0;
    // 가로 검사
    for (int r = 0; r < 5; r++) {
        if (all_of(board[r].begin(), board[r].end(), [](int i) { return i == -1; })) bingo++;
        if (bingo == 3) return bingo;
    }

    // 세로 검사
    vector<int> column;
    for (int c = 0; c < 5; c++) {
        for (int k = 0; k < 5; k++) 
            column.push_back(board[k][c]);

        if (all_of(column.begin(), column.end(), [](int i) { return i == -1; })) bingo++;
        if (bingo == 3) return bingo;
        column.clear();
    }

    // 대각선 검사
    vector<int> diag(5, 0);
    for (int i = 0; i < 5; i++) diag[i] = board[i][i];
    if (all_of(diag.begin(), diag.end(), [](int k) { return k == -1; })) bingo++;
    if (bingo == 3) return bingo;
    
    for (int i = 0; i < 5; i++) diag[i] = board[i][4-i];
    if (all_of(diag.begin(), diag.end(), [](int k) { return k == -1; })) bingo++;
    if (bingo == 3) return bingo;

    return bingo;
}

pair<int,int> checkValue(vector<vector<int>>& board, int target) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == target) {
                return make_pair(i, j);
            }
        }
    }

    return make_pair(-1, -1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> board;
    for (int i = 0; i < 5; i++) {
        int k;
        vector<int> line;
        for (int j = 0; j < 5; j++) {
            cin >> k; 
            line.push_back(k);
        }

        board.push_back(line);
    }

    
    int x;
    int r, c;
    int bingo, count = -1;
    for (int v = 1; v <= 25; v++) {
        cin >> x;
        if (count != -1) continue;

        pair<int, int> pos = checkValue(board, x);
        r = pos.first;
        c = pos.second;
        board[r][c] = -1;
        
        bingo = countBingo(board);
        if (bingo == 3) count = v;
        
    }
    cout << count;
}