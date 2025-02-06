#include <iostream>
using namespace std;

int main() {
    int a, k; cin >> a >> k;

    if (a == 1) cout << 1;
    else if (k == 0) cout << a;
    else if (k != 0) {
        if (a % 2 == 0) cout << 1;
        else cout << a;
    }
}