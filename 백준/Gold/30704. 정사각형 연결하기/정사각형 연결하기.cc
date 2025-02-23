#include <iostream>
#include <math.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;

int main() {
    FASTIO;

    int T; cin >> T;
    while (T--) {
        ll N; cin >> N;

        ll sqr = sqrtl(N);
        if (pow(sqr, 2) == N) {
            cout << sqr * 4 << '\n';
        }
        else {
            ll w = sqr + 1;
            ll h;
            if (N % w != 0) h = (N / w) + 1;
            else h = N / w;
            
            cout << (w+h)*2 << '\n';
        }
    }
}