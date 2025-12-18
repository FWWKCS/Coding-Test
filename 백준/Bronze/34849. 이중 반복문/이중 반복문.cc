#include <iostream>
using namespace std;

int main() {
    long long N; cin >> N;
    if (N*N <= 100'000'000) cout << "Accepted";
    else cout << "Time limit exceeded";
}