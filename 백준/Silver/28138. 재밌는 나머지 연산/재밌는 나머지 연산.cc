#include <iostream>
#include <math.h>
using namespace std;
using ll = long long;

int main() {
    ll N, R; cin >> N >> R;
    ll answer = 0;
    
    ll Q = N-R;
    for (int i = 1; i <= sqrtl(Q); i++) {
        if (Q % i != 0) continue;

        ll j = Q / i;

        if (N % i == R) answer += i;
        if (i != j && N % j == R) answer += j;
    }

    cout << answer;
}