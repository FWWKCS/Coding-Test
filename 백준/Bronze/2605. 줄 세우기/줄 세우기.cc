#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;

    vector<int> line;
    vector<int> stack;
    int x;
    for (int i = 1; i <= N; i++) {
        cin >> x;
        for (int k = 0; k < x; k++) {
            stack.push_back(line.back());
            line.pop_back();
        }

        line.push_back(i);
        for (int k = 0; k < x; k++) {
            line.push_back(stack.back());
            stack.pop_back();
        }
    }

    for (int x : line) cout << x << ' ';
}