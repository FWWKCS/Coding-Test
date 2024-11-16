#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    for (int r = 0; r < N*5; r++) {
        for (int c = 0; c < N*5; c++) {
            if (r / N != 0 && c / N == 1) cout << ' ';
            else if (r / N != 4 && c / N == 3) cout << ' ';
            else cout << '@';
        }
        cout << '\n';
    }
}