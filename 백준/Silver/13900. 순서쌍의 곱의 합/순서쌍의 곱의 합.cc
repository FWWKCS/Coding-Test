#include <iostream>
#include <vector>
using ll = long long;
using namespace std;


int main() {
    int N; cin >> N;
    vector<ll> num(N);
    for (auto &x : num) cin >> x;
    for (int i = 1; i < N; i++) num[i] += num[i-1];

    long long answer = 0;
    for (int i = 1; i < N; i++) {
        ll t = num[i]-num[i-1];
        answer += t * num[i-1];
    }

    cout << answer;
}