#include <iostream>
#include <map>
#include <iomanip>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int total = 0;
map<string, double> trees;

int main() {
    FASTIO;
    cout << fixed << setprecision(4);

    string s;
    while (getline(cin, s)) {
        if (s == "EOF") break;

        trees[s]++;
        total++;
    }

    for (auto t : trees) {
        cout << t.first << ' ' << (t.second/total)*100 << '\n';
    }
}