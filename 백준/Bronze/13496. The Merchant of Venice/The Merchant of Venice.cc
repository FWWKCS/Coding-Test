#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;
    int K; cin >> K;
    for (int i = 1; i <= K; i++) {
        int cost = 0;
        int N, S, D; cin >> N >> S >> D;
        while (N--) {
            int d, v; cin >> d >> v;
            if (d <= S*D) cost += v;
        }

        cout << "Data Set " << i << ":\n" << cost << "\n\n";
    }
}