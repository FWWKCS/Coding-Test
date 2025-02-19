#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int ari = 1023;
    int kg[10] = {0, };

    int S, M; cin >> S >> M;

    for (int k = 9; k >= 0; k--) {
        if (M >= pow(2, k)) {
            kg[k] = 1;
            M -= pow(2, k);
        }
    }

    S -= ari;
    if (S <= 0) {
        cout << "No thanks";
        return 0;
    }

    for (int k = 9; k >= 0; k--) {
        if (kg[k] && S >= pow(2, k)) {
            S -= pow(2, k);
            if (S == 0) {
                cout << "Thanks";
                return 0;
            }
        }
    }

    cout << "Impossible";
    return 0;
}