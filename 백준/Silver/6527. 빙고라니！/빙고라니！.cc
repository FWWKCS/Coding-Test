#include <iostream>
#include <algorithm>
#include <set>
#include <cctype>
#include <string>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

set<string> words;
int games = 0, total = 0;

void remake(string s) {
    string res = "";
    for (char c : s) {
        if (isalpha(c)) res += tolower(c);
        else {
            if (!res.empty()) words.insert(res);
            res = "";
        }
    }

    if (!res.empty()) words.insert(res);
}

int main() {    
    FASTIO;

    string s;
    while (cin >> s) {
        if (s == "IOF") break;
        if (s == "BULLSHIT") {
            games++;
            total += words.size();
            words.clear();
        }
        else {
            remake(s);
        }

    }
    
    int r = __gcd(total, games);
    cout << total / r << " / " << games / r << '\n';
}