#include <iostream>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int G, C, E; cin >> G >> C >> E;
        if (C >= E) cout << 0;
        else if (G == 1) cout << E - C;
        else if (G == 2) cout << (E-C) * 3;
        else cout << (E-C) * 5;

        cout << '\n';
    }
}