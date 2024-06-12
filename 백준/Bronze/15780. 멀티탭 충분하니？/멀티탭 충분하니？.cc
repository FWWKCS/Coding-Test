#include <iostream>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    int total = 0;
    int x;
    for (int i = 0; i < K; i++) {
        cin >> x;
        total += x - (x / 2);
    }

    if (total >= N) cout << "YES";
    else cout << "NO";
}