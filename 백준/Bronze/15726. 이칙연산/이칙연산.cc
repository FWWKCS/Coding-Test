#include <iostream>
using namespace std;

int main() {
    long long A, B, C, x, y;
    cin >> A >> B >> C;
    
    x = (double)A*B/C;
    y = (double)A/B*C;

    cout << (long long)max(x, y);
}