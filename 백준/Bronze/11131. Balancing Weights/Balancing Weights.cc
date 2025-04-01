#include <iostream>
using namespace std;

int T, N;

int main() {
    cin >> T;
    while (T--) {
        int N; cin >> N;
        int I = 0;
        while (N--) {
            int x; cin >> x;
            I += x;
        }

        if (I < 0) cout << "Left";
        else if (I > 0) cout << "Right";
        else cout << "Equilibrium";
        
        cout << '\n';
    }
}