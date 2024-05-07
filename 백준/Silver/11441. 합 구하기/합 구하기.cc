#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    vector<int> A(1, 0);
    for (int x = 1; x <= N; x++) {
        int k; cin >> k;
        A.push_back(k);
        A[x] = A[x-1] + k;
    }

    int M; cin >> M;
    int i, j;
    for (int x = 1; x <= M; x++) {
        cin >> i >> j;
        cout << A[j] - A[i-1] << '\n';
    }
    
}