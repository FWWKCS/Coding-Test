#include <iostream>
#include <set>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main() {
    FASTIO;

    string msg; getline(cin, msg);
    int N; cin >> N;
    set<string> members = {"swi"};
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        members.insert(s);
    }

    int M; cin >> M;

    // 1. dongho 적발
    if (members.find("dongho") != members.end()) {
        cout << "dongho";
        return 0;
    }

    for (int i = 0; i < M; i++) {
        string s; cin >> s;
        if (members.find(s) != members.end()) members.erase(s);
    }

    // 2. 목격담이 없는 단 한명
    if (members.size() == 1) {
        cout << *members.begin();
        return 0;
    }

    // 3. bumin
    if (members.find("bumin") != members.end()) {
        cout << "bumin";
        return 0;
    }

    // 4. cake
    if (members.find("cake") != members.end()) {
        cout << "cake";
        return 0;
    }

    // 5. lawyer
    if (members.find("lawyer") != members.end()) {
        cout << "lawyer";
        return 0;
    }

    // 6. 사전 순으로 가장 빠른 사람
    cout << *members.begin();
}