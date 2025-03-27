#include <iostream>
#include <math.h>
using namespace std;

int X, Y, R; 

int A = 0, B = 0;

void check(int T) {
    if (pow(T-X, 2) < pow(R, 2)) A++;
    else if (pow(T-X, 2) == pow(R, 2)) B++;
}

int main() {
    int N; cin >> N;
    cin >> X >> Y >> R;
    while (N--) {
        int T; cin >> T; check(T);
    }

    cout << A << ' ' << B;
}