#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    int M, K; cin >> M >> K;
    int need = M * K;

    vector<int> pens;
    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        pens.push_back(x);
    }

    sort(pens.rbegin(), pens.rend());

    for (int i = 1; i < N; i++) {
        pens[i] = pens[i] + pens[i-1];
    }

    for (int i = 0; i < N; i++) {
        if (pens[i] >= need) {
            cout << i+1;
            return 0;
        }
    }

    cout << "STRESS";

}