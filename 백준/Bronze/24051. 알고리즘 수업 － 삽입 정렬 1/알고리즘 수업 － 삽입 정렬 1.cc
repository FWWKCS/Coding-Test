#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N, K; cin >> N >> K;
    vector<int> A(N);
    for (auto &x : A) cin >> x;

    // vector<int> save = {0};

    int count = 0;
    int save = 0;
    for (int i = 1; i < N; i++) {
        int loc = i-1;
        int newItem = A[i];

        while (0 <= loc and newItem < A[loc]) {
            A[loc+1] = A[loc];
            // save.push_back(A[loc+1]);
            if (count < K) {
                save = A[loc+1];    
                count++;
            }
            loc--;
        }
        if (loc+1 != i) {
            A[loc+1] = newItem;
            if (count < K) {
                save = A[loc+1];    
                count++;
            }
        }
    }

    // for (auto x : save) cout << x << ' ';
    if (count < K) cout << -1;
    else cout << save;
}