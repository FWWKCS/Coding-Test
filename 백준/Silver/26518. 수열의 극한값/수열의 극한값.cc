#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    double b, c, a1, a2; cin >> b >> c >> a1 >> a2;

    // 특성방정식 x^2 - bx - c = 0 의 최대값 해

    double x1 = (b + sqrt(pow(b, 2) + 4*c)) / 2;
    double x2 = (b - sqrt(pow(b, 2) + 4*c)) / 2;

    cout << fixed << setprecision(6) << max(x1, x2);
}