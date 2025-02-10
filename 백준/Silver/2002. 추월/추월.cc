#include <iostream>
#include <map>
#include <set>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N; cin >> N;
    map<string, int> in;

    for (int i = 1; i <= N; i++) {
        string s; cin >> s;
        in[s] = i;
    }

    set<string> detected;
    map<string, int> out;
    for (int i = 1; i <= N; i++) {
        string s; cin >> s;
        out[s] = i;
    }

    for (auto target : in) {
        if (detected.find(target.first) != detected.end()) continue;

        for (auto comp : in) {
            string targetName = target.first;
            string compName = comp.first;
            
            if (targetName == compName) continue;

            int targetRank = target.second;
            int compRank = comp.second;

            if (targetRank > compRank && out[targetName] < out[compName]) {
                detected.insert(targetName);
                break;
            }
        }
    }

    cout << detected.size();
}