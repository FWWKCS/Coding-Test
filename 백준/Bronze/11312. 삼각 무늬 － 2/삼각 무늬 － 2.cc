#include <iostream>
#include <math.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        long long A, B; cin >> A >> B;

        cout << (long long)pow(A/B, 2) << '\n';
    }
}