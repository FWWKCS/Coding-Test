#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {
    string S; cin >> S;
    map<char, set<int>>cards = {
        {'P', set<int>()},
        {'K', set<int>()},
        {'H', set<int>()},
        {'T', set<int>()}
    };

    for (int i = 0; i < S.length(); i+=3) {
        char shape = S[i];
        int num = stoi(S.substr(i+1, 2));

        if (cards[shape].find(num) != cards[shape].end()) {
            cout << "GRESKA";
            return 0;
        }
        else cards[shape].insert(num);
    }

    cout << 13 - cards['P'].size() << ' ';
    cout << 13 - cards['K'].size() << ' ';
    cout << 13 - cards['H'].size() << ' ';
    cout << 13 - cards['T'].size();
}