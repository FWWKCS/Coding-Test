#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K; cin >> N >> K;
    vector<int> seq;
    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        seq.push_back(x);
    }

    nth_element(seq.begin(), seq.begin()+K-1, seq.end());
    cout << seq[K-1];
}