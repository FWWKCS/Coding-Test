#include <iostream>
using namespace std;

int main() {
    long long R, C, N; cin >> R >> C >> N;
    long long r = 0, c = 0;
    if (R % N != 0) r = (R/N) + 1;
    else r = R/N;

    if (C % N != 0) c = (C/N) + 1;
    else c = C/N;

    cout << r * c;
}