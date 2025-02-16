#include <iostream>
#include <queue>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N; cin >> N;
    priority_queue<int, vector<int>, less<int>> LQ; // 중간값이거나 보다 작은 값중 큰 것
    priority_queue<int, vector<int>, greater<int>> RQ; // 중간값보다 큰 값중 작은 것

    while (N--) {
        int x; cin >> x;
        
        if (LQ.size() == RQ.size()) // LQ에 추가
            LQ.push(x);
        else RQ.push(x);

        // root 교환 검증
        if (!LQ.empty() && !RQ.empty() && LQ.top() > RQ.top()) {
            // swap
            int LR = LQ.top(), RR = RQ.top();
            LQ.pop(); RQ.pop();
            LQ.push(RR); RQ.push(LR);
        }

        // 중간값은 LQ의 루트에서 정의
        cout << LQ.top() << '\n';
    }
}