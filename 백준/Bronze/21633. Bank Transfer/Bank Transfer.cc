#include <iostream>
#include <iomanip>
using namespace std;
using ld = long double;

int main() {
    cout << fixed << setprecision(2);
    ld k; cin >> k;

    ld x = k * 0.01 + 25;
    if (x < 100) cout << 100;
    else cout << (ld)min(x, (ld)2000);
}