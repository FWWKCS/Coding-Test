#include <iostream>
using namespace std;

int main() {
    int X, L, R; cin >> X >> L >> R;

    if (X <= L) cout << L;
    else if (X >= R) cout << R;
    else cout << X;
}