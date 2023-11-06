#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B;
    long long tmp;
    cin >> A >> B;

    if (A != B) cout << abs(A-B)-1 << '\n';
    else cout << 0 << '\n';

    if (A > B) {
        tmp = B;
        B = A;
        A = tmp;
    }

    for (long long i = A+1; i < B; i++) {
        cout << i << " ";
    }
}