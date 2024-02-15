#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int T; cin >> T;
    int V, E;
    for (int i = 0; i < T; i++) {
        cin >> V >> E;
        cout << 2 - (V-E) << '\n';
    }
}