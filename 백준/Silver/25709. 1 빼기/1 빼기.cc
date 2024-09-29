#include <iostream>
#include <string>
#include <list>
#include <queue>
using namespace std;

int answer = 0;

void fillQueue(int cur, queue<char> &q) {
    string N = to_string(cur);
    for (auto x : N) {
        if (x == '1') answer++;
        else q.push(x);
    }
}

int getValue(queue<char> &q) {
    string v = "";
    while (!q.empty()) {
        v += q.front();
        q.pop();
    }
    return v.empty() ? 0 : stoi(v);
}

int main() {
    string N; cin >> N;
    
    queue<char> q;

    for (auto x : N) {
        if (x == '1') answer++;
        else q.push(x);
    }

    int v = getValue(q);
    fillQueue(v, q);

    while (!q.empty() && v != 0) {
        // -1 산술연산
        int v = getValue(q);
        while (v % 10 != 1) {
            v--;
            answer++;
        }
        
        fillQueue(v, q);
    }
    
    cout << answer;
}