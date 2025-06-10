#include <iostream>
#include <queue>
#include <vector>
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

// 비교 함수 객체 정의 (second 기준 내림차순)
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second; // greater second -> higher priority
    }
};

int main() {
    FASTIO;

    int N, K; cin >> N >> K;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> jewel;
    priority_queue<int, vector<int>, greater<int>> bag; 

    for (int i = 0; i < N; i++) {
        int M, V; cin >> M >> V;
        jewel.push({M, V});
    }

    for (int i = 0; i < K; i++) {
        int C; cin >> C;
        bag.push(C);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> tmp;

    long long answer = 0;
    while (!bag.empty()) {
        int cur = bag.top();
        bag.pop();
        
        // 현재 가방의 크기보다 작은 모든 보석을 가져오기
        while (!jewel.empty()) {
            int target = jewel.top().first;
            if (target <= cur) {
                tmp.push(jewel.top());
            }
            else break;

            jewel.pop();
        }

        // 가치가 가장 큰 보석이 우선순위가 높음
        if (!tmp.empty()) {
            answer += tmp.top().second;
            tmp.pop();
        }
    }

    cout << answer;
}