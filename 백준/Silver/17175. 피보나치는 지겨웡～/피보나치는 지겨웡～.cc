#include <iostream>
#define MOD 1'000'000'007
using namespace std;

int main() {
    int n; cin >> n;
    int fibo[n+2] = {1, 1, };

    for (int i = 2; i <= n+2; i++) {
        fibo[i] = (1 + fibo[i-2] + fibo[i-1]) % MOD;
    }
    
    cout << fibo[n];
}