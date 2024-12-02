#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main() {
    double A1, P1; cin >> A1 >> P1;
    double R1, P2; cin >> R1 >> P2;

    double whole = R1 * R1 * M_PI;

    if (A1/P1 > whole/P2) cout << "Slice of pizza";
    else cout << "Whole pizza";
}