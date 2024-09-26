#include <iostream>
using namespace std;

int main() {
    long long K, N; cin >> K >> N;

    if (N == 1) {
        cout << -1;
        return 0;
    }

    long long X;
    if ((N*K) % (N-1) != 0) {
        X = ((N*K) / (N-1)) + 1;
    }
    else X = (N*K) / (N-1);

    cout << X;
}