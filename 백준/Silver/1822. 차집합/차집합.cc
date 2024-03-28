#include <bits/stdc++.h>
using namespace std;

int main() {
    int nA, nB;
    cin >> nA >> nB;

    set<int> A;
    set<int> B;

    int x;
    for (int i = 0; i < nA; i++) {
        cin >> x;
        A.insert(x);
    }

    for (int i = 0; i < nB; i++) {
        cin >> x;
        B.insert(x);
    }

    set<int> C;

    set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(C, C.begin()));

    if (C.empty()) cout << 0;
    else {
        cout << C.size() << '\n';   
        for (auto x : C) cout << x << ' ';
    }
}