#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

void add(vector<int>& E, set<int>& S, int index) {
    if (S.size() == 6) {
        for (auto x : S) cout << x << ' ';
        cout << '\n';
        return;
    }

    for (int i = index; i < E.size(); i++) {
        S.insert(E[i]);
        add(E, S, i+1);
        S.erase(E[i]);
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x;
    while (true) {
        cin >> x;
        if (x == 0) break;

        vector<int> elements;
        int e;
        for (int i = 0; i < x; i++) {
            cin >> e;
            elements.push_back(e);
        }

        set<int> lotto;
        add(elements, lotto, 0);
        cout << '\n';
    }
}