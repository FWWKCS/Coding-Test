#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

pair<char, int> form(string s) {
    string num = "";
    for (char c : s) {
        if (isdigit(c)) num += c;
    }
    return {s[0], stoi(num)};
}

int main() {
    FASTIO;

    vector<pair<char, int>> target;
    queue<pair<char, int>> next;

    stack<pair<char, int>> wait;
    queue<pair<char, int>> line;

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            string s; cin >> s;
            pair<char, int> f = form(s);
            line.push(f);
            target.push_back(f);
        }
    }

    sort(target.begin(), target.end());
    for (auto s : target) next.push(s);

    while (!line.empty()) {
        auto current = next.front();
        // cout << "찾습니다: " << current.first << '-' << current.second << '\n';

        if (!wait.empty() && wait.top() == current) {
            // cout << wait.top().first << '-' << wait.top().second << "  대기에서 나오세요\n\n";
            wait.pop();
            next.pop();
        }
        else if (line.front() != current) {
            // cout << line.front().first << '-' << line.front().second << "  대기로 들어가세요\n\n";
            wait.push(line.front());
            line.pop();
        }
        else if (line.front() == current) {
            // cout << "줄에서 나오세요\n\n";
            line.pop();
            next.pop();
        }
    }

    while (!wait.empty()) {
        auto current = next.front();
        // cout << "찾습니다: " << current.first << '-' << current.second << '\n';

        if (wait.top() == current) {
            // cout << wait.top().first << '-' << wait.top().second << "  대기에서 나오세요\n\n";
            wait.pop();
            next.pop();
        }
        else {
            cout << "BAD";
            return 0;
        }
    }

    cout << "GOOD";
    return 0;
}