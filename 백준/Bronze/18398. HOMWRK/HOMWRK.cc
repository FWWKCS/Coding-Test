#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int T; cin >> T;
    int N;
    while (T--) {
        cin >> N;
        for (int t = 0; t < N; t++) {
            int A, B; cin >> A >> B; 
            cout << A + B << ' ' << A * B << '\n';
        }
    }
}