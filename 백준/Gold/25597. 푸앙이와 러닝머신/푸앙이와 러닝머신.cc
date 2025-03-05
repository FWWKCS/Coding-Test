#include <iostream>
using namespace std;
using ll = long long;

ll X, T;

int main() {
    cin >> X >> T;

    ll a8 = X/8;
    X %= 8;
    
    ll a4 = X/4;
    X %= 4;
    
    ll a1 = X;

    // 불가능한 상황
    if (a8 + a4 + a1 > T) {
        cout << -1;
        return 0;
    }


    // 8을 4로 분할해도 가능하다면
    if (a8*2 + a4 + a1 <= T) {
        // 8을 4로 분할하여 누르는 버튼을 2개로 줄인다
        a4 += a8*2;
        a8 = 0;
    }

    // 4를 1로 분할해도 가능하다면
    if (a8 + 4*a4 + a1 <= T) {
        // 4를 1로 분할하여 누르는 버튼을 1개로 줄인다
        a1 += 4*a4;
        a4 = 0;
    }

    // cout << a8 << ' ' << a4 << ' ' << a1 << '\n';

    ll press = 0;
    if (a8 > 0) press++;
    if (a4 > 0) press++;
    if (a1 > 0) press++;

    cout << press << '\n';
    if (a8 > 0) cout << T-(a8+a4+a1) << " 8\n";
    if (a4 > 0) cout << T-(a4+a1) << " 4\n";
    if (a1 > 0) cout << T-a1 << " 1\n";
}