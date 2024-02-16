#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    deque<int> deque;

    string command;
    int x;
    for (int i = 0; i < N; i++) {
        cin >> command;
        
        if (command == "push_front") {
            cin >> x;
            deque.push_front(x);
        }
        else if (command == "push_back") { 
            cin >> x;
            deque.push_back(x);
        }
        else if (command == "pop_front") {
            if (deque.empty()) {
                cout << -1 << '\n'; 
                continue;
            }
            cout << deque.front() << '\n';
            deque.pop_front();
        }
        else if (command == "pop_back") {
            if (deque.empty()) {
                cout << -1 << '\n';
                continue;
            }
            cout << deque.back() << '\n';
            deque.pop_back();
        }
        else if (command == "size") cout << deque.size() << '\n';
        else if (command == "empty") {
            if (deque.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (command == "front") {
            if (deque.empty()) cout << -1 << '\n';
            else cout << deque.front() << '\n'; 
        }        
        else {
            if (deque.empty()) cout << -1 << '\n';
            else cout << deque.back() << '\n';
        }
    }
}