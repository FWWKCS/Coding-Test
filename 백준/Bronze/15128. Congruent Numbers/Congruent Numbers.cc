#include <iostream>
using namespace std;

int main() {
    long long p1, q1, p2, q2; cin >> p1 >> q1 >> p2 >> q2;
    if ((p1*p2) % (q1*q2*2) != 0) cout << 0;
    else cout << 1;
}