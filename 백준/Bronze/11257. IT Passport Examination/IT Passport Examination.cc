#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    while (N--) {
        int info, S, I, T; cin >> info >> S >> I >> T;

        if (S + I + T >= 55 && S >= 11 && I >= 8 && T >= 12) {
            cout << info << ' ' << S+I+T << " PASS\n";
        }
        else cout << info << ' ' << S+I+T << " FAIL\n";
    }
}