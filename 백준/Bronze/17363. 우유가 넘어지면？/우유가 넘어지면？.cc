#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main() {
    int N, M; cin >> N >> M;

    vector<vector<char>> table(N, vector<char>(M));
    for (auto &r : table) {
        for (auto &c : r) cin >> c;
    }

    vector<vector<char>> answer(M, vector<char>(N));
    for (int r = 0; r < N; r++) {
        for (int c = M-1; c > -1; c--) {
            char target;
            switch (table[r][c]) {
                case '.': {
                    target = '.';
                    break;
                }
                case 'O': {
                    target = 'O';
                    break;
                }
                case '-': {
                    target = '|';
                    break;
                }
                case '|': {
                    target = '-';
                    break;
                }
                case '/': {
                    target = '\\';
                    break;
                }
                case '\\': {
                    target = '/';
                    break;
                }
                case '^': {
                    target = '<';
                    break;
                }
                case '<': {
                    target = 'v';
                    break;
                }
                case 'v': {
                    target = '>';
                    break;
                }
                case '>': {
                    target = '^';
                    break;
                }
            }
            answer[M-1-c][r] = target;
        }
    }

    for (auto r : answer) {
        for (auto c : r) cout << c;
        cout << '\n';
    }
}