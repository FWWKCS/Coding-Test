#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    int turn = 1;
    int need = 0;

    while (true) {
        need++;
        N -= need;
        if (N < 0) {
            if (turn) {
                cout << -N;
                break;
            }
            else {
                cout << 0;
                break;
            }
        }
        turn = !turn;
        // cout << N << ' ' << turn << '\n';
    }
}