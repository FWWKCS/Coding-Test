#include <iostream>
using namespace std;

int main() {
    int k, w, m; cin >> k >> w >> m;

    if ((w-k) % m != 0) cout << ((w-k) / m) + 1;
    else cout << (w-k) / m;
}