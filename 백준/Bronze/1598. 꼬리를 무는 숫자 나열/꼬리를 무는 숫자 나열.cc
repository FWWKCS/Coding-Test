#include <iostream>
using namespace std;

int main() {
    int A, B; cin >> A >> B;
    int rA, rB, cA, cB;

    if (A % 4 != 0) rA = A / 4 + 1;
    else rA = A / 4;

    if (B % 4 != 0) rB = B / 4 + 1;
    else rB = B / 4;

    cA = A % 4;
    if (cA == 0) cA = 4;

    cB = B % 4;
    if (cB == 0) cB = 4;

    cout << abs(rA - rB) + abs(cA - cB);
}