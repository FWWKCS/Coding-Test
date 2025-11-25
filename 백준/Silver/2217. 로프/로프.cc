#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N; cin >> N;
    vector<int> ropes(N);
    for (auto &x : ropes) cin >> x;

    sort(ropes.rbegin(), ropes.rend());

    int answer = 0;
    for (int i = 0; i < N; i++) {
        answer = max(answer, ropes[i] * (i+1));
    }

    cout << answer;
}