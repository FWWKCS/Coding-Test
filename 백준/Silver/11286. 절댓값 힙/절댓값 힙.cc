#include <iostream>
#include <queue>
using namespace std;

struct p {
    int absV;
    int realV;

    // 생성자
    p(int a, int r) : absV(a), realV(r) {}
};

struct compare {
    bool operator() (p a, p b) {
        if (a.absV != b.absV) return a.absV > b.absV;
        return a.realV > b.realV;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    int x;
    priority_queue<p, vector<p>, compare> heap;

    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x != 0) heap.push(p(abs(x), x));
        else if (x == 0 && heap.empty()) cout << 0 << '\n';
        else {
            p tmp = heap.top();
            cout << tmp.realV << '\n';
            heap.pop();
        }
    }
}