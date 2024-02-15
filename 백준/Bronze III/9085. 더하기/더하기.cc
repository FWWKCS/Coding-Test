#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        int N; cin >> N;
        vector<int> list(N);
        for (int j = 0; j < N; j++) cin >> list[j];

        cout << accumulate(list.begin(), list.end(), 0) << '\n';
    }
}