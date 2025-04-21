#include <iostream>
using namespace std;

int main() {
    int k = -1, v = 1e9;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x < v) {
            v = x;
            k = i;
        }
    }

    cout << k;
}