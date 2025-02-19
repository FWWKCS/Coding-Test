#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    ll k = 1;
    for (int i = 2; i <= N; i++) {
        k = (k * i);
        while (k >= 10 && k % 10 == 0) k /= 10;
        k %= 1'000'000;
    }

    cout << k % 10;
}