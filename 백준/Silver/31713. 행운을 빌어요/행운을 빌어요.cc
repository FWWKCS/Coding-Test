#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;
    
    int T; cin >> T;
    while (T--) {
        int A, B; cin >> A >> B;
        int p = 0, q = 0;

        bool found = false;
        while (true) {
            for (int x = (B+q)/4; x > -1; x--) {
                int y = (B+q)-(4*x);
                if (y % 3 == 0 && x+(y/3) >= A) {
                    p = x+(y/3);
                    found = true;
                    break;
                }
            }

            if (found) break;
            q++;
        }   

        cout << p+q-A << '\n';
    }
}