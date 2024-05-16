#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int R, C; cin >> R >> C;
    int A, B; cin >> A >> B;

    for (int i = 0; i < R*A; i++) {
        for (int j = 0; j < C*B; j++) {
            if ((i/A)%2 == 0 && (j/B)%2 == 0) cout << 'X';
            else if ((i/A)%2 == 0 && (j/B)%2 == 1) cout << '.';
            else if ((i/A)%2 == 1 && (j/B)%2 == 0) cout << '.';
            else cout << 'X';
        }
        cout << '\n';
    }
}