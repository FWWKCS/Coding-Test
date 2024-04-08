#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    int F, x; cin >> F;
    for (int i = 0; i < N-1; i++) {
        cin >> x;
        int v = __gcd(F, x);

        cout << F / v << '/' << x / v << '\n';
    }
}