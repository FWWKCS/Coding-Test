#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using d = double;

int main() {
    FASTIO;

    int T; cin >> T;
    cout << fixed << setprecision(6);
    while (T--) {
        int mode; cin >> mode;
        switch (mode) {
            case 1: {
                d x, y; cin >> x >> y;
                d theta = atan2(y, x);
                if (theta < 0) theta += 2*M_PI;
                
                cout << sqrt(pow(x, 2) + pow(y, 2)) << ' ' << theta << '\n';
                break;
            }
            case 2: {
                d r, theta; cin >> r >> theta;
                cout << r*cos(theta) << ' ' << r*sin(theta) << '\n';
                break;
            }
        }
    }
}