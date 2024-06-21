#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, X; cin >> N >> X;

    vector<int> T;
    int k;
    for (int i = 0; i < N; i++) {
        cin >> k;
        T.push_back(k);
    }

    int idx = 0;
    while (true) {
        if (T[idx] < X) break;
        else {
            idx++;
            if (idx == N) idx = 0;

            X++;
        }
    }

    cout << idx + 1;
}