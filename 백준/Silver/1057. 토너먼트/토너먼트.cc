#include <iostream>
using namespace std;

int main() {
    int N, A, B; cin >> N >> A >> B;

    int round = 1;
    while (true) {
        if ((B % 2 == 0 && B-1 == A) || (A % 2 == 0 && A-1 == B)) break;

        if (A % 2 != 0) A = A/2 + 1;
        else A /= 2;

        if (B % 2 != 0) B = B/2 + 1;
        else B/= 2;

        round++;
    }

    cout << round;
}