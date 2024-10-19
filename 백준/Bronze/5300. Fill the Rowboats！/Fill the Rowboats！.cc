#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        if (i != N) {
            if (i % 6 == 0) cout << i << " Go! ";
            else cout << i << " ";
        }
        else cout << i << " Go! ";
    }
}