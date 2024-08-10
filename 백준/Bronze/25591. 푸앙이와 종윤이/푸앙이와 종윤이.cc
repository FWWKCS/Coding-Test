#include <iostream>
using namespace std;

int main() {
    int x, y; cin >> x >> y;

    int a, b, c, d, q, r;

    a = 100 - x;
    b = 100 - y;
    c = 100 - (a + b);
    d = a * b;
    q = d / 100;
    r = d % 100;

    printf("%d %d %d %d %d %d\n", a, b, c, d, q, r);
    cout << c + q << ' ' << r;
}