#include <iostream>
using namespace std;

int T, M, P1, P2;

int main() {
    cin >> T;
    while (T--) {
        cin >> M;
        int cur = 0, neg = 0;
        while (M--) {
            cin >> P1 >> P2;
            cur += P1;
            if (cur < P2) {
                neg += P2-cur;
                cur = 0;
            }
            else cur -= P2;
        }
        cout << neg << '\n';
    }
}