#include <iostream>
#include <vector>
using namespace std;

int T(int n) {
    return n * (n+1) / 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> W(1, 0);
    for (int i = 1; i <= 300; i++) {
        W.push_back(W[i-1] + i*T(i+1));
    }

    int T; cin >> T;
    int q; 
    for (int i = 0; i < T; i++) {
        cin >> q;
        cout << W[q] << '\n';
    }

}