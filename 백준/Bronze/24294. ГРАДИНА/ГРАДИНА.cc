#include <iostream>
using namespace std;

int main() {
    int w1, h1, w2, h2; cin >> w1 >> h1 >> w2 >> h2;

    int total = 0;
    total += (h1+h2) * 2;
    if (w1 < w2) total += w2*2;
    else if (w1 > w2) total += w1*2;
    else total += w1*2;

    cout << total + 4;
}