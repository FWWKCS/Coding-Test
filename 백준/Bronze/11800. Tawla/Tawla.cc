#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    map<int, string> name = {
        {1, "Yakk"},
        {2, "Doh"},
        {3, "Seh"},
        {4, "Ghar"},
        {5, "Bang"},
        {6, "Sheesh"},
    };

    map<int, string> same = {
        {1, "Habb Yakk"},
        {2, "Dobara"},
        {3, "Dousa"},
        {4, "Dorgy"},
        {5, "Dabash"},
        {6, "Dosh"},
    };

    for (int i = 1; i <= T; i++) {
        int A, B;
        vector<int> value(2, 0);
        cin >> A >> B;
        value[0] = A; value[1] = B;

        sort(value.rbegin(), value.rend());

        if (A == B) cout << "Case " << i << ": " << same[A] << '\n';
        else if (value[0] == 6 && value[1] == 5) cout << "Case " << i << ": Sheesh Beesh\n";
        else cout << "Case " << i << ": " << name[value[0]] << ' ' << name[value[1]] << '\n';
    }
}