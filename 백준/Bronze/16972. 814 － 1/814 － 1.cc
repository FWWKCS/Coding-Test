#include <iostream>
#include <random>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count = 0;
    for (int y = -8140; y <= 8140; y+=20) {
        for (int x = -8140; x <= 8140; x+=20) {
            cout << x << ' ' << y << '\n';
            count++;
            if (count == 812) break;
        }
        if (count == 812) break;
    }
    cout << "8140 8140\n8139 8139";
}