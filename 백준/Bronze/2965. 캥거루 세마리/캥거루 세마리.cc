#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int count = 0;
    int tmp;
    while (true) {
        if (B - A == 1 && C - B == 1) break;

        if (B - A > C - B) {
            C = A + 1;
            tmp = B;
            B = C;
            C = tmp;

            count++;
        } else {
            A = C - 1;
            tmp = B;
            B = A;
            A = tmp;

            count++;
        }
    }

    cout << count;
}