#include <iostream>
using namespace std;
using ll = long long;

ll remain[1002] = {0, };

int main() {
    remain[1] = 1;
    for (int i = 2; i <= 1001; i++) {
        remain[i] = (remain[i-1] * i);
        while (remain[i] >= 10 && remain[i] % 10 == 0) remain[i] /= 10;
        remain[i] %= 1'000'000;
    }
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << remain[n] % 10 << '\n';
    }
}