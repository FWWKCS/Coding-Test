#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int seq[10000001] = {0, };

int main() {
    FASTIO;

    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        seq[x]++;

        if (seq[x] == 2) {
            cout << x;
            break;
        }
    }
}