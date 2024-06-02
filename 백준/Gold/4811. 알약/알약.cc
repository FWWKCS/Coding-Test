#include <iostream>
#include <vector>
using namespace std;

long long Cn(int n, long long C) {
    return 2 * (2 * n + 1) * C / (n + 2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Catalan number

    vector<long long> catalan(1, 1);
    for (int i = 1; i < 30; i++) {
        catalan.push_back(Cn(i, catalan.back()));
    }

    int Q;
    while (true) {
        cin >> Q;
        if (Q == 0) break;

        cout << catalan[Q-1] << '\n';
    }
}