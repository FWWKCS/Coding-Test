#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    int x;
    vector<pair<int, int>> stack;
    for (int k = 1; k <= N; k++) {
        cin >> x;
        while (!stack.empty() && stack.back().second < x){
            stack.pop_back();
        }

        if (stack.empty()) {
            cout << 0 << ' ';
            stack.push_back(make_pair(k, x));
        }
        else {
            cout << stack.back().first << ' ';
            stack.push_back(make_pair(k, x));
        }
    }
}