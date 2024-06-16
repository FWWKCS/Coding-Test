#include <iostream>
#include <iomanip>
using namespace std;

#define M_PI 3.14159265358979323846

int main() {
    double r; cin >> r;

    cout << fixed << setprecision(6) << M_PI * r * r << '\n';
    cout << fixed << setprecision(6) << r * r * 2;
}