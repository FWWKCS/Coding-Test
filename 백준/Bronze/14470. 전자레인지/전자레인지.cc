#include <iostream>
using namespace std;

int main() {
    int total = 0;
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;

    if (A < 0) {
        total += (abs(A) * C);
        A = 0;
    }
    if (A == 0) total += D + (B-A) * E;

    if (A > 0) total += (B-A) * E;

    cout << total;
}