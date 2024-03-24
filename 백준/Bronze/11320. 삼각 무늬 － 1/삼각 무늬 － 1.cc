#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    int A, B;

    for (int i = 0; i < T; i++) {
        cin >> A >> B;
        int Sa, Sb;

        Sa = pow(A, 2);
        Sb = pow(B, 2);

        cout << Sa/Sb << '\n';
    }
}