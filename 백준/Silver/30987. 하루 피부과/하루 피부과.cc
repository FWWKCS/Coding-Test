#include <iostream>
#include <cmath>
using namespace std;

int a, b, c, d, e;
int F(int x) {
    return (a/3)*pow(x, 3) + ((b-d)/2)*pow(x, 2) + (c-e)*x; 
}

int main() {
    int x1, x2; cin >> x1 >> x2;
    cin >> a >> b >> c >> d >> e;

    // f = ax^2 + bx + c
    // g = dx + e

    // f-g = ax^2 +(b-d)x + (c-e)
    // F = a/3 x^3 + (b-d)/2 x^2 + (c-e)x

    // F(x2) - F(x1)
    cout << F(x2) - F(x1);
}