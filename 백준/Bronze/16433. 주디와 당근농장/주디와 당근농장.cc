#include <iostream>
using namespace std;

int main() {
    int N, R, C; cin >> N >> R >> C;

    if ((R % 2 == 1 && C % 2 == 1) || (R % 2 == 0 && C % 2 == 0)) {
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                if ((r % 2 == 1 && c % 2 == 1) || (r % 2 == 0 && c % 2 == 0)) cout << 'v';
                else cout << '.';
            }
            cout << '\n';
        }
    }
    else {
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                if ((r % 2 == 1 && c % 2 == 1) || (r % 2 == 0 && c % 2 == 0)) cout << '.';
                else cout << 'v';
            }
            cout << '\n';
        }
    }
}