#include <iostream>
#include <sstream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    set<char> S;
    string line;
    string N, M;
    string tmp;
    while (getline(cin, line)) {
        if (line == "EOF") break;

        int count = 0;
        istringstream iss(line);
        iss >> N >> M;

        for (int i = stoi(N); i <= stoi(M); i++) {
            tmp = to_string(i);
            for (int k = 0; k < tmp.length(); k++) S.insert(tmp[k]);
            if (S.size() == tmp.length()) count++;
            S.clear();
        }

        cout << count << '\n';
    }
}