#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int L, P, V;
    int count = 1;
    while (true) {
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0) break;

        cout << "Case " << count << ": " << (V / P) * L + min(L, V % P) << '\n';
        count++;
    }
}