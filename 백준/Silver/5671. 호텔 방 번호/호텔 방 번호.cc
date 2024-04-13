#include <iostream>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<bool> possible(5001, false);
    
    set<char> S;
    string tmp;
    for (int i = 1; i <= 5000; i++) {
        tmp = to_string(i);
        for (int k = 0; k < tmp.length(); k++) S.insert(tmp[k]);
        if (tmp.length() == S.size()) possible[i] = true;
        S.clear();
    }

    string line;
    int N, M;
    while (getline(cin, line)) {
        if (line == "EOF") break;

        istringstream iss(line);
        iss >> N >> M;

        int count = 0;
        for (int i = N; i <= M; i++) {
            if (possible[i]) count++;
        }
        cout << count << '\n';
    }
}