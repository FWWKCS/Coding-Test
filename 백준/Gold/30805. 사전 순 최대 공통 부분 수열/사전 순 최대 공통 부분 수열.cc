#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    }
};

int main() {
    FASTIO;

    int A; cin >> A;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> qA;
    for (int i = 1; i <= A; i++) {
        int k; cin >> k;
        qA.push({k, i});
    }

    int B; cin >> B;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> qB;
    for (int i = 1; i <= B; i++) {
        int k; cin >> k;
        qB.push({k, i});
    }

    vector<int> answer;

    int lA = -1, lB = -1;
    while (!qA.empty() && !qB.empty()) {
        // A에서 가장 큰 수와 B에서 가장 큰 수를 뽑아 비교
        auto topA = qA.top();
        int kA = topA.first, iA = topA.second;

        auto topB = qB.top();
        int kB = topB.first, iB = topB.second;

        if (iA < lA) {
            qA.pop();
            continue;
        }

        if (iB < lB) {
            qB.pop();
            continue;
        }

        // A가 B보다 크면 A의 것을 제거
        if (kA > kB) qA.pop();

        // B가 A보다 크면 B의 것을 제거
        else if (kA < kB) qB.pop();

        // 같으면 공통 수열의 가장 마지막이 될 요소로 포함 가능
        else {
            answer.push_back(kA);
            lA = iA; lB = iB; // 이후에 넣을 수는 각 수열의 마지막 인덱스보다 뒤에 존재해야한다
            
            qA.pop();
            qB.pop();
        }
    }

    cout << answer.size() << '\n';
    for (auto x : answer) cout << x << ' ';
}