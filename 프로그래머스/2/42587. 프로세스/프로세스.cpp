#include <string>
#include <vector>
#include <deque>
using namespace std;

bool upperExist(deque<pair<int, int>>& dq, int pr) {
    for (auto e : dq) {
        if (e.first > pr) return true; 
    }
    return false;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int, int>> dq;
    for (int i = 0; i < priorities.size(); ++i) dq.push_back({priorities[i], i});
    int turn = 1;
    while (!dq.empty()) {
        // 1. pop
        int cur = dq.front().first;
        int idx = dq.front().second;
        dq.pop_front();
        
        // 2. check
        if (upperExist(dq, cur)) dq.push_back({cur, idx});
        else {
            // 3. run
            if (idx == location) answer = turn;
            turn++;
        }
    }
    
    return answer;
}