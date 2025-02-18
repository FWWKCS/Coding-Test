#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    long double a; cin >> a;
    cout << fixed << setprecision(6) << sqrt(a) * 4;
}