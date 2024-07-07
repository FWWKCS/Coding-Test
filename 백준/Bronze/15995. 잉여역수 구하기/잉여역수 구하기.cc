#include <iostream>
using namespace std;

int main() {
    int a, m; cin >> a >> m;

    int x = 1;
    while (true) {
        if ((a*x) % m == 1) {
            cout << x;
            return 0;
        }
        x++;
    }
}