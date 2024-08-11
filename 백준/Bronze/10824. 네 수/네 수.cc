#include <iostream>
#include <string.h>
using namespace std;

int main() {
    string A, B, C, D; cin >> A >> B >> C >> D;
    long long X = stoll(A + B);
    long long Y = stoll(C + D);

    cout << X + Y;
}
