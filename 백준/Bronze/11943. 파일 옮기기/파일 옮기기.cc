#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A, B, C, D;
    cin >> A >> B;
    cin >> C >> D;

    cout << min(A+D, B+C);
}