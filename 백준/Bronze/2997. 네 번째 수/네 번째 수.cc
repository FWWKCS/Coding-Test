#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> seq;
    int v;
    for (int i = 0; i < 3; i++) {
        cin >> v;
        seq.push_back(v);
    }

    sort(seq.begin(), seq.end());
    
    int a = seq[0], b = seq[1],  c = seq[2];
    int d, x;
    
    // case 1. a x b c
    d = c - b;
    x = a + d;
    if (b - x == x - a) {
        cout << x;
        return 0;
    }

    // case 2. a b x c
    d = b - a;
    x = b + d;
    if (c - x == x - b) {
        cout << x;
        return 0;
    }

    // case 3. a b c x
    d = c - b;
    x = c + d;
    if (x - c == d) {
        cout << x;
        return 0;
    }
}