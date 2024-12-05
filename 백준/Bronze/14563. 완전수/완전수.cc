#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int x; cin >> x;
        int total = 0;
        for (int i = 1; i < x; i++) {
            if (x % i == 0) total += i;
        }

        if (x != 1 && x == total) cout << "Perfect\n";
        else if (x > total) cout << "Deficient\n";
        else cout << "Abundant\n";
    }
}