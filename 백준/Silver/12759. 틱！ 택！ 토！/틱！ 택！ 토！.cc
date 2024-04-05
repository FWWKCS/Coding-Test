#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkBingo(vector<vector<int>>& board, int turn) {
    bool nonZero, same;

    // 가로 검사
    vector<int> tmp;
    for (int r = 1; r <= 3; r++) {
        for (int c = 1; c <= 3; c++) tmp.push_back(board[r][c]);
        nonZero = all_of(tmp.begin(), tmp.end(), [](int i) { return i != 0; });
        same = all_of(tmp.begin(), tmp.end(), [turn](int i) { return i == turn; });
        if (nonZero && same) return true;

        tmp.clear();
    }

    tmp.clear();
    // 세로 검사
    for (int c = 1; c <= 3; c++) {
        for (int r = 1; r <= 3; r++) tmp.push_back(board[r][c]);
        nonZero = all_of(tmp.begin(), tmp.end(), [](int i) { return i != 0; });
        same = all_of(tmp.begin(), tmp.end(), [turn](int i) { return i == turn; });
        if (nonZero && same) return true;

        tmp.clear();
    } 

    // 대각선 검사
    for (int i = 1; i <= 3; i++) tmp.push_back(board[i][i]);
    nonZero = all_of(tmp.begin(), tmp.end(), [](int i) { return i != 0; });
    same = all_of(tmp.begin(), tmp.end(), [turn](int i) { return i == turn; });
    if (nonZero && same) return true;
    
    tmp.clear();
    
    for (int i = 1; i <= 3; i++) tmp.push_back(board[i][4-i]);
    nonZero = all_of(tmp.begin(), tmp.end(), [](int i) { return i != 0; });
    same = all_of(tmp.begin(), tmp.end(), [turn](int i) { return i == turn; });
    if (nonZero && same) return true;
    

    return false;
}

int main() {
    int turn; cin >> turn;
    // 1 : O / 2 : X 
    vector<vector<int>> board(4, vector<int>(4));

    int r, c;
    int win = 0;
    for (int i = 0; i < 9; i++) {
        cin >> r >> c;
        if (turn == 1) {
            board[r][c] = 1;
            if (win == 0 && checkBingo(board, turn)) win = 1;
            turn = 2;
        }
        else {
            board[r][c] = 2;
            if (win == 0 && checkBingo(board, turn)) win = 2;
            turn = 1;
        }
    }

    cout << win;
}