#include <iostream>
#include <queue>
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main() {
    FASTIO;

    int N; cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int _ = 0; _ < N; _++) {
            int x; cin >> x;
            pq.push(x);
    }

    for (int _ = 1; _ < N; _++) {
        for (int __ = 0; __ < N; __++) {
            int x; cin >> x;
            pq.push(x);
            pq.pop();
        }
    }

    cout << pq.top();
}