#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    long long t[n+1] = {1, };

    for (int i = 1; i <= n; i++) {
        long long sum = 0;
        for (int k = 0; k < i; k++) {
            sum += t[k] * t[i-1-k];
        }
        t[i] = sum;
    }

    cout << t[n];
}