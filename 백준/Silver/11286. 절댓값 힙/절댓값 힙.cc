#include <iostream>
#include <queue>
using namespace std;

struct compare {
    bool operator() (pair<int, int>& a, pair<int, int>& b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    int x;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> heap;

    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x != 0) heap.push(make_pair(abs(x), x));
        else if (x == 0 && heap.empty()) cout << "0\n";
        else {
            cout << heap.top().second << '\n';
            heap.pop();
        }
    }
}