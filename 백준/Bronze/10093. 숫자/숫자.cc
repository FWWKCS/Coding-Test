#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    int tmp;
    cin >> A >> B;

    if (A != B) cout << abs(A-B)-1 << '\n';
    else cout << 0 << '\n';
    
    if (A > B) {
        tmp = B;
        B = A;
        A = tmp;
    }

    for (int i = A+1; i < B; i++) {
        cout << i << " ";
    }
}