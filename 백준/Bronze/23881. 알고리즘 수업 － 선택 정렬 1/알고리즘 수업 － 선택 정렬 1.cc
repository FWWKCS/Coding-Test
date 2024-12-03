#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void selection_sort(vector<int>& A, int K) {
    int count = 0;
    for (int i = A.size()-1; i > 0; i--) {
        int maxV = 0, idx = -1;
        for (int k = 0; k <= i; k++) {
            if (maxV < A[k]) {
                maxV = A[k];
                idx = k;
            }
        }   

        if (i != idx) {
            count++;

            int tmp = A[i];
            A[i] = A[idx];
            A[idx] = tmp;
            
            if (count == K) {
                cout << A[idx] << ' ' << A[i];
            }
        }
    }

    if (count < K) cout << -1;
}

int main() {
    FASTIO;

    int N, K; cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        A[i] = x;
    }

    selection_sort(A, K);
}