#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <algorithm>
#include <iomanip>
using namespace std;
using ld = long double;

int main() {
    cout << fixed << setprecision(3);

    ld x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    ld d = sqrtl(powl(x2-x1, 2) + powl(y2-y1, 2));
    if (d == 0) { 
        if (r1 <= r2) cout << M_PI*r1*r1;
        else cout << M_PI*r2*r2;

        return 0;
    }
    else if (d >= r1+r2) {
        cout << 0.000; 
        return 0;
    }
    else if (r1 < r2 && d+r1 <= r2) {
        cout << M_PI*r1*r1;
        return 0.000;
    }
    else if (r2 < r1 && d+r2 <= r1) {
        cout << M_PI*r2*r2;
        return 0.000;
    }

    ld th1 = 2*acosl(clamp((powl(d, 2)+powl(r1, 2)-powl(r2, 2))/(2*d*r1), -1.0L, 1.0L));
    ld th2 = 2*acosl(clamp((powl(d, 2)+powl(r2, 2)-powl(r1, 2))/(2*d*r2), -1.0L, 1.0L));

    ld A1 = powl(r1, 2)*(th1 - sinl(th1))/2;
    ld A2 = powl(r2, 2)*(th2 - sinl(th2))/2;

    cout << A1+A2;
}