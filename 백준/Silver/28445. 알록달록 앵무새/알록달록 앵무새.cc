#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<pair<string, string>> children;

int main() {
    string fb, ft, mb, mt;
    cin >> fb >> ft >> mb >> mt;

    vector<string> parents = {fb, ft, mb, mt};
    for (string s : parents) {
        for (string t : parents) children.insert({s, t});
    }

    for (auto p : children) cout << p.first << ' ' << p.second << '\n';
}