#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, F; cin >> N >> F;
    int v = 0;

    while (true) {
        int X = N / 100 * 100;
        if ((X+v) % F == 0) {
            cout << setfill('0') << setw(2) << v;
            break;
        }

        v++;
    }
}