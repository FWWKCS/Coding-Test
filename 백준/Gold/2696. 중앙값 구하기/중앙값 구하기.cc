#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int M; cin >> M;
        priority_queue<int, vector<int>, less<int>> left;
        priority_queue<int, vector<int>, greater<int>> right;
        vector<int> medians;

        for (int k = 1; k <= M; k++) {
            int x; cin >> x;
            if (k % 2) left.push(x);
            else right.push(x);
            
            if (!left.empty() && !right.empty() && left.top() > right.top()) {
                left.push(right.top());
                right.pop();
                right.push(left.top());
                left.pop();
            }

            if (k % 2) medians.push_back(left.top());
        }

        cout << medians.size() << '\n';
        for (int i = 0; i < medians.size(); i++) {
            cout << medians[i] << ' ';
        }
    }
}