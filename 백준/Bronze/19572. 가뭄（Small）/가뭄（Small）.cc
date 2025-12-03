#include <iostream>
#include <iomanip>
using namespace std;
using ld = long double;

int main() {
    ld d1, d2, d3; cin >> d1 >> d2 >> d3;

    // a + b = d1
    // a + c = d2
    // b + c = d3
    
    // b-c = d1-d2
    // b+c = d3
    // 2b = d1-d2+d3
    
    // a-b = d2-d3
    // a+b = d1
    // 2a = d2-d3+d1

    // c-a = d3-d1
    // c+a = d2
    // 2c = d3-d1+d2

    ld a = (d2-d3+d1) / 2;
    ld b = (d1-d2+d3) / 2;
    ld c = (d3-d1+d2) / 2;

    if (a <= 0 || b <= 0 || c <= 0) cout << -1;
    else cout << 1 << '\n' << fixed << setprecision(1) << a << ' ' << b << ' ' << c;
}