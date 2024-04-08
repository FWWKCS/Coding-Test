#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    string input;

    for (int i = 0; i < N; i++) {
        cin >> input;

        int len = sqrt(input.length());
        vector<vector<char>> board(len, vector<char> (len));
        for (int r = 0; r < len; r++) {
            for (int c = 0; c < len; c++) {
                board[r][c] = input[len*r + c];
            }
        }

        for (int c = len-1; c > -1; c--) {
            for (int r = 0; r < len; r++) {
                cout << board[r][c];
            }
        }

        cout << '\n';
    }
}