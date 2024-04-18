#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string target; cin >> target;
    int N; cin >> N;
    string x;

    vector<string> V;
    for (int i = 0; i < N; i++) {
        cin >> x;
        bool right = true;
        for (int k = 0; k < x.length(); k++) {
            if (target[k] == '*') continue;
            else if (target[k] != x[k]) {
                right = false;
                break;
            }
        }

        if (right) V.push_back(x);
    }

    cout << V.size() << '\n';
    for (auto v : V) cout << v << '\n';
}