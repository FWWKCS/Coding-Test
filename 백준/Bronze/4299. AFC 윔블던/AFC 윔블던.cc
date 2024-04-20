#include <iostream>
using namespace std;

int main() {
    int A, B; cin >> A >> B;
    int x, y;

    x = (A+B)/2;
    y = A-x;

    if ((A+B) % 2 != 0) cout << -1;
    else if (A < B) cout << -1;
    else if (x < 0 || y < 0) cout << -1;
    else cout << max(x, y) << ' ' << min(x, y);
}