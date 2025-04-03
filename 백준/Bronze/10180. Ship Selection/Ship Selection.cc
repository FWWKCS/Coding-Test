#include <iostream>
using namespace std;
using ld = long double;

int T, N;
ld D;
ld vi, fi, ci;

int main() {
    cin >> T;
    while (T--) {
        int total = 0;
        cin >> N >> D;
        while (N--) {
            cin >> vi >> fi >> ci;
            ld t = D / vi;
            if (t * ci <= fi) total++;
        }

        cout << total << '\n';
    }
}