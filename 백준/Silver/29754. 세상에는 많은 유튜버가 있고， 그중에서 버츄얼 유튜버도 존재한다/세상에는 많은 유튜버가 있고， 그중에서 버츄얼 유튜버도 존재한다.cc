#include <iostream>
#include <string>
#include <vector>
#include <map>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N, M;
string name, start, fin;
int day;

int week;

int timeFormat(string& s, string& e) {
    string sh = s.substr(0, 2);
    string sm = s.substr(3, 2);

    string eh = e.substr(0, 2);
    string em = e.substr(3, 2);

    return (stoi(eh)*60 + stoi(em)) - (stoi(sh)*60 + stoi(sm));
}

int main() {
    FASTIO;

    cin >> N >> M;
    map<string, vector<pair<int, int>>> info;
    while (N--) {
        cin >> name >> day >> start >> fin;
        if (day % 7 == 0) week = (day / 7) - 1;
        else week = day / 7;

        if (info.find(name) == info.end()) {
            vector<pair<int, int>> tmp(M/7, {0, 0});
            info[name] = tmp;
        }
        
        info[name][week].first++;
        info[name][week].second += timeFormat(start, fin);
    }

    bool found = false;
    for (auto x : info) {
        bool isReal = true;
        for (auto r : x.second) {
            int rD = r.first, rT = r.second;
            if (rD < 5 || rT < 3600) {
                isReal = false;
                break;
            }
        }

        if (isReal) {
            found = true;
            cout << x.first << '\n';
        }
    }   

    if (!found) cout << -1;
}