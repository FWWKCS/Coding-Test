#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    if (N % 2 == 0) {
        for (int i = 1; i <= N; i++) {
            if (i % 2 == 1) cout << 1 << ' ';
            else cout << 2 << ' '; 
        }
    }
    else {
        for (int i = 1; i < N; i++) {
            if (i % 2 == 1) cout << 1 << ' ';
            else cout << 2 << ' '; 
        }
        cout << 3;
    }
}