#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double d1, d2; cin >> d1 >> d2;
    const double PI = 3.141592;

    cout << fixed << setprecision(6) << (2 * d1) + (2 * PI * d2);
}