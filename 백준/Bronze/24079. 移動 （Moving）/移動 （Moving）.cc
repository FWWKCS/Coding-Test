#include <iostream>
using namespace std;
using ld = long double;

int main() {
    ld X, Y, Z; cin >> X >> Y >> Z;
    cout << (X+Y <= Z+0.5);
}