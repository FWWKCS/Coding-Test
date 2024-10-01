#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    while (true) {
        double x; cin >> x;
        if (x == 0) return 0;

        cout << fixed << setprecision(2) << 1 + x + x*x + x*x*x + x*x*x*x << '\n';
    }    
}