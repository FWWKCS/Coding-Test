#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    vector<int> towers(1, 0);
    int x; 
    for (int i = 0; i < N; i++) {
        cin >> x;
        towers.push_back(x);
    }

    vector<pair<int, int>> stack;
    for (int k = 1; k <= N; k++) {
        while (!stack.empty() && stack.back().second < towers[k]){
            stack.pop_back();
        }

        if (stack.empty()) {
            cout << 0 << ' ';
            stack.push_back(make_pair(k, towers[k]));
        }
        else {
            cout << stack.back().first << ' ';
            stack.push_back(make_pair(k, towers[k]));
        }
    }
}