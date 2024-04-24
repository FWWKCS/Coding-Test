#include <iostream>
using namespace std;

int main() {
    long long A, B, C;
    cin >> A >> B >> C;

    cout << (long long)max((double)A*B/C, (double)A/B*C);
}