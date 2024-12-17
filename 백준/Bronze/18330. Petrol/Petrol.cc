#include <iostream>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    k += 60;

    long long cost = 0;

    if (n <= k) cost += n * 1500;
    else {
        cost += k * 1500;
        n -= k;
        cost += n * 3000;
    }

    cout << cost;
}