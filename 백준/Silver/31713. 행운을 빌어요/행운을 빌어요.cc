#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;
    
    int T; cin >> T;
    while (T--) {
        int A, B; cin >> A >> B;
        int answer = 1e9;

        for (int k = A; k <= 1000; k++) {
            if (B > 4*k) continue;
            answer = min(answer, (k-A)+max(3*k-B, 0));
        }
        cout << answer << '\n';
    }
}