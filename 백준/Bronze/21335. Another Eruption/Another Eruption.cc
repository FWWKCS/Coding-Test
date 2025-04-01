#define _USE_MATH_DEFINES
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using ld = long double;

int main() {
    ld a; cin >> a;

    cout << fixed << setprecision(6);

    ld r = sqrtl(a / M_PI);
    cout << 2*r*M_PI;
}