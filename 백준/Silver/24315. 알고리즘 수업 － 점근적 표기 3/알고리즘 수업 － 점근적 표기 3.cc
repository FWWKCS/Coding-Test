#include <iostream>
using namespace std;

int main() {
    int a1, a0; cin >> a1 >> a0; 
    int c1, c2; cin >> c1 >> c2;
    int n0; cin >> n0;

    if (c1*n0 <= a1*n0+a0 && a1*n0+a0 <= c2*n0 && c1 <= a1 && a1 <= c2) cout << 1;
    else cout << 0;
}