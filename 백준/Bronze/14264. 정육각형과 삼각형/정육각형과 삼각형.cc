#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using ld = long double;

int main() {
    ld L; cin >> L;

    cout << fixed << setprecision(10);
    cout << L*L*sqrtl(3)/4;
}