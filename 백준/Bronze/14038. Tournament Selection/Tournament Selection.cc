#include <iostream>
using namespace std;

int main() {
    int c = 6; 
    int winCount = 0;
    while (c--) {
        char x; cin >> x;
        if (x == 'W') winCount++;
    }

    if (winCount >= 5) cout << 1;
    else if (winCount >= 3) cout << 2;
    else if (winCount >= 1) cout << 3;
    else cout << -1;
}