#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N;
    while (true) {
        cin >> N;
        if (N < 1) break;
        set<string> type;
        string s;
        while (N--) {
            cin >> s;
            sort(s.begin(), s.end());

            string press = "";
            for (char c : s) {
                if (*(press.end()-1) != c) press += c; 
            }

            type.insert(press);
        }   
        cout << type.size() << '\n';
    }
}