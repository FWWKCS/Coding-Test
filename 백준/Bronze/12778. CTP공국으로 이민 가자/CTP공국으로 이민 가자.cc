#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        int M;
        char type;

        cin >> M >> type;
        if (type == 'C') {
            for (int j = 0; j < M; j++) {
                char q; cin >> q;
                cout << int(q)-64 << ' ';
            }
            cout << '\n';
        }
        else {
            for (int j = 0; j < M; j++) {
                int q; cin >> q;
                cout << char(q+64) << ' ';
            }
            cout << '\n';
        }
    }
}