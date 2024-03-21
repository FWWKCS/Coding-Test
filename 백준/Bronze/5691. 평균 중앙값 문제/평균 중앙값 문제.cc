#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A, B;
    while (true) {
        cin >> A >> B;
        if (A == 0 && B == 0) break;

        cout << 3*A - (A+B) << '\n';
    }
}