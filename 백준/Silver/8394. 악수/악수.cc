#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;

    int a = 1, b = 2, tmp;
    if (n == 1) cout << a;
    else if (n == 2) cout << b;
    else { // n >= 3
        for (int i = 3; i <= n; i++) {
            tmp = (a + b) % 10;
            a = b % 10;
            b = tmp % 10;
        }
       cout << b;
    }

}