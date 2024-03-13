#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, D, P;
    cin >> A >> B >> C >> D >> P;

    int X = 0, Y = 0;

    X = A * P;
    if (P <= C) Y = B;
    else {
        Y += B;
        P -= C;

        Y += P * D;
    }

    cout << min(X, Y);
}