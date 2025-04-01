#include <iostream>
#include <iomanip>
#include <cmath>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ld = long double;

ld ax, ay, bx, by, cx, cy, dx, dy, ex, ey, fx, fy;
ld hx, hy, gx, gy;
ld tS, sS;

ld rounding(ld x) {
    return round(x * 1000) / 1000;
}

int main() {
    FASTIO;
    cout << fixed << setprecision(3);

    while (true) {
        cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy >> ex >> ey >> fx >> fy;
        tS = abs((dx*(ey-fy))+(ex*(fy-dy))+(fx*(dy-ey)))/2;
        if (tS == 0) return 0;

        sS = abs((ax*(by-cy))+(bx*(cy-ay))+(cx*(ay-by)));

        ld k = tS / sS;

        hx = ax + k * (cx-ax);
        hy = ay + k * (cy-ay);
        gx = bx + (hx-ax);
        gy = by + (hy-ay);

        cout << rounding(gx) << ' ' << rounding(gy) << ' '
             << rounding(hx) << ' ' << rounding(hy) << '\n';
    }
}