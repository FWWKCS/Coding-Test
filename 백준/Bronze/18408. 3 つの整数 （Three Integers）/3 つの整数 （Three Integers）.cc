#include <iostream>
using namespace std;

int main() {
    int A, B, C; cin >> A >> B >> C;
    int one = 0, two = 0;
    if (A == 1) one++;
    else two++;

    if (B == 1) one++;
    else two++;

    if (C == 1) one++;
    else two++;

    if (one > two) cout << 1;
    else cout << 2;
}