#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    for (int i = 1; i <= 5; i++) {
        for (int r = 0; r < N; r++) {
            if (i % 2 == 1) {
                for (int c = 0; c < 5*N; c++) cout << '@';
                cout << '\n';
            }
            else {
                for (int c = 0; c < N; c++) cout << '@';
                cout << '\n';
            }
        }
    }
}