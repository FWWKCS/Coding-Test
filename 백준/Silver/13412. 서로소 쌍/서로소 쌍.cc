#include <iostream>
#include <cmath>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int T; cin >> T;
    while (T--) {
        int x; cin >> x;
        int answer = 0;
        
        for (int i = 1; i <= sqrtl(x); i++) {
            if (x % i == 0) {
                int a = i, b = x / i;
                if (__gcd(a, b) == 1) answer++;
            }
        }

        cout << answer << '\n';
    }
}