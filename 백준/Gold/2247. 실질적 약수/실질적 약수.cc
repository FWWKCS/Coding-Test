#include <iostream>
#define MOD 1'000'000
using namespace std;

int main() {
    int n; cin >> n;

    int CSOD_N = 0;
    for (int i = 2; i < n; i++) {
        int v = (n / i) - 1;
        CSOD_N = (CSOD_N + ((v * i) % MOD)) % MOD;
    }

    cout << CSOD_N;
}