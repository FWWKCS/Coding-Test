#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    string A, B;

    int dist;
    for (int i = 0; i < N; i++) {
        dist = 0;
        cin >> A >> B;
        for (int k = 0; k < A.length(); k++) {
            if (A[k] != B[k]) dist++;
        }
        cout << "Hamming distance is " << dist << ".\n";
    }
}