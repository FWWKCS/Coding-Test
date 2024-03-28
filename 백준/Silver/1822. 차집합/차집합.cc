#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int nA, nB;
    cin >> nA >> nB;

    set<int> A;

    int x;
    for (int i = 0; i < nA; i++) {
        cin >> x;
        A.insert(x);
    }

    for (int i = 0; i < nB; i++) {
        cin >> x;
        if (A.find(x) != A.end()) A.erase(x);
    }

    cout << A.size() << '\n';
    if (A.size() != 0) {
        for (auto e : A) cout << e << ' ';
    }
}