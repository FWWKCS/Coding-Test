#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        if ((x % 2 == 1 && i % 2 != 1)
         || (x % 2 == 0 && i % 2 != 0)) {
            cout << "NO";
            return 0;
            } 
    }
    cout << "YES";
}