#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;

    long long count = 5;
    int d = 7;
    for (int i = 1; i < N; i++) {
        count += d;
        count %= 45678;
        d += 3;
    }

    cout << count;
}