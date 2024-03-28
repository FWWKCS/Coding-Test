#include <bits/stdc++.h>
using namespace std;

vector<int> get_prime() {
    vector<int> p;
    for (int i = 0; i <= 1050; i++) p.push_back(i);

    for (int k = 2; k < int(sqrt(1050))+1; k++) {
        for (int x = pow(k, 2); x <= 1050; x+=k) p[x] = 0;
    }

    return p;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string target; cin >> target;
    int value = 0;

    for (int i = 0; i < target.length(); i++) {
        if ('a' <= target[i] && target[i] <= 'z') value += target[i] - 'a' + 1;
        else value += target[i] - 'A' + 27;
    }

    vector<int> p = get_prime();
    
    if (p[value] != 0) cout << "It is a prime word.";
    else cout << "It is not a prime word.";
}