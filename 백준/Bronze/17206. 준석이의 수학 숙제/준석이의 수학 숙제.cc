#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;

ll table[80'001] = {0, };

int main() {
    FASTIO;
    
    for (int i = 1; i <= 80'000; i++) {
        table[i] = table[i-1];
        if (i % 3 == 0 || i % 7 == 0) table[i] += i;
    }

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        cout << table[N] << '\n';
    }
}