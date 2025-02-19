#include <iostream>
#define MAX 1'000'000
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int num[MAX+1];

bool isRepeat(int k) {
    int visited[10] = {0, };

    string s = to_string(k);
    for (int i = 0; i < s.size(); i++) {
        if (visited[s[i]-'0']) return true;
        else visited[s[i]-'0'] = 1;
    }

    return false;
}

int main() {
    FASTIO;

    int idx = 1;
    int v = 1;
    while (idx <= MAX) {
        if (!isRepeat(v)) {
            num[idx] = v;
            idx++;
        }
        v++;
    }


    while (true) {
        int n; cin >> n;
        if (!n) return 0;

        cout << num[n] << '\n';
    }
}