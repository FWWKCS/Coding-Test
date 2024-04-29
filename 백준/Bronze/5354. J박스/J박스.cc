#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        int x; cin >> x;
        if (x == 1) {
            cout << "#\n\n";
            continue;
        }
        
        for (int l = 0; l < x; l++) cout << '#';
        cout << '\n';
        for (int l = 0; l < x-2; l++) {
            cout << '#';
            for (int k = 0; k < x-2; k++) cout << 'J';
            cout << "#\n";
        }
        for (int l = 0; l < x; l++) cout << '#';
        cout << "\n\n";
    }
}