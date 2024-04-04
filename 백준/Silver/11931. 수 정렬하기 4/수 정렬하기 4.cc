#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> seq;
    int N; cin >> N;
    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        seq.push_back(x);
    }

    sort(seq.rbegin(), seq.rend());

    for (int k : seq) cout << k << '\n'; 
}