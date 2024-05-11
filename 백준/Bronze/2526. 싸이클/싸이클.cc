#include <iostream>
#include <map>
using namespace std;

int main() {
    int N, P; cin >> N >> P;
    map<int, int> mod = {
        {N, 1},
    };

    int cnt = 2;
    int m = (N*N) % P;
    mod.insert(make_pair(m, cnt));
    cnt++;

    while (true) {
        m = (m*N) % P;
        if (mod.find(m) != mod.end()) {
            cout << cnt - mod[m];
            return 0;
        }

        mod.insert(make_pair(m, cnt));
        cnt++;
    }
}