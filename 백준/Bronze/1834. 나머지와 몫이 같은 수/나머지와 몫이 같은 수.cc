#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    
    long long total = 0;
    for (long long i = 1; i < N; i++) {
        total += i * (long long)N + i;
    }

    cout << total;
}