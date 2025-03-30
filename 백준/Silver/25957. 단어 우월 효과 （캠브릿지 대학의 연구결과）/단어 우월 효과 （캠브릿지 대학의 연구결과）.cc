#include <iostream>
#include <map>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

vector<string> words;
map<pair<string, vector<int>>, int> idx;

int N, M;

vector<int> check(string x) {
    vector<int> info(26, 0);
    for (char c : x) info[c-'a']++;

    return info;
}

int main() {
    FASTIO;

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        words.push_back(s);
        string f = {s[0], s.back()}; 
        idx[{f, check(s)}] = i;
    }

    cin >> M;
    while (M--) {
        string t; cin >> t;
        string h = {t[0], t.back()};
        int k = idx[{h, check(t)}];
        cout << words[k] << ' ';
    }
}    