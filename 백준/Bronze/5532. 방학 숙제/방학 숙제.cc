#include <bits/stdc++.h>
using namespace std;

int main() {
    int L, A, B, C, D;
    cin >> L >> A >> B >> C >> D;

    int total = 0;

    if (A % C == 0) total = A / C;
    else total = A / C + 1;

    if (B % D == 0) total = max(total, B / D);
    else total = max(total, B / D + 1);

    cout << L - total; 
}