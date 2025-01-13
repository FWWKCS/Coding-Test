#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int n;
int answer = 1e9;
vector<int> rel;

void dfs(int depth, int mask, int selected) {
    if (depth == n) {
        // 선택한 인원들로부터 모든 사람에게 광고를 보이는지 확인
        if (mask == (int)pow(2, n)-1) answer = min(answer, selected);
        // cout << mask << '\n';
        return;
    }

    // select
    dfs(depth+1, mask | rel[depth], selected+1);

    // not select
    dfs(depth+1, mask, selected);
}

int main() {
    int T; cin >> T;
    while (T--) {
        cin >> n;
        rel.assign(n, 0);
        for (int i = 0; i < n; i++) {
            int d; cin >> d;
            rel[i] |= (1 << i); // 자기자신은 항상 포함
            for (int j = 1; j <= d; j++) {
                int x; cin >> x;
                rel[i] |= (1 << (x-1));
            }
        }

        dfs(0, 0, 0);
        cout << answer << '\n';
        answer = 1e9;
    }
}