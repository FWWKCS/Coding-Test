#include <iostream>
using namespace std;

int main() {
    int count = 10;
    int degree = 0;
    while (count--) {
        int x; cin >> x;
        if (x == 1) degree += 90;
        else if (x == 2) degree += 180;
        else degree -= 90;
        
        if (degree < 0) degree += 360;
        degree %= 360;

        // cout << degree << '\n';
    }

    if (degree == 0) cout << 'N';
    else if (degree == 90) cout << 'E';
    else if (degree == 180) cout << 'S';
    else cout << 'W';
}