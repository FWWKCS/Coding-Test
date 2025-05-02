#include <iostream>
#include <iomanip>
using namespace std;
using ld = long double;

int main() {
    ld a, b, c; cin >> a >> b >> c;
    cout << fixed << setprecision(3);

    cout << 2*a*0.229*0.324 + 2*b*0.297*0.42 + c*0.21*0.297;
}