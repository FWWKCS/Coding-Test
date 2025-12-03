#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for (auto &x : A) cin >> x;

    vector<int> save = {0};

    // int save = 0;
    for (int i = 1; i < N; i++) {
        int loc = i-1;
        int newItem = A[i];

        while (0 <= loc and newItem < A[loc]) {
            A[loc+1] = A[loc];
            save.push_back(A[loc+1]);    
            loc--;
        }
        if (loc+1 != i) {
            A[loc+1] = newItem;
            save.push_back(A[loc+1]);
        }
    }

    // for (auto x : save) cout << x << ' ';
    if (save.size()-1 < K) cout << -1;
    else cout << save[K];
}