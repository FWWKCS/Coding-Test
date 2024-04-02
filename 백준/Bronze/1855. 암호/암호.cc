#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int N; cin >> N;
    string S; cin >> S;

    int row = S.length() / N;
    vector<deque<char>> board;

    deque<char> R;
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < N; c++) {
            if (r % 2 == 0) {
                // 정방향 삽입
                R.push_back(S[N*r+c]);
            }
            else {
                // 역방향 삽입
                R.push_front(S[N*r+c]);
            }
        }

        board.push_back(R);
        R.clear();
    }

    // 순차읽기
    for (int c = 0; c < N; c++) {
        for (int r = 0; r < row; r++) {
            cout << board[r][c];
        }
    }
}
