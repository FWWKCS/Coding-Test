#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sorted(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, S; cin >> N >> M >> S;
    int x, y;

    vector<vector<int>> sc;
    for (int i = 0; i < N; i++) {
        vector<int> line(2, 0);
        cin >> x >> y;
        line[0] = x;
        line[1] = x+y;

        sc.push_back(line);
    }

    sort(sc.begin(), sc.end(), sorted);

    // 앞 시간이 비는 경우
    if (sc[0][0] >= M) {
        cout << 0;
        return 0;
    }

    for (int i = 1; i < N; i++) {
        if (sc[i][0] - sc[i-1][1] >= M) {
            cout << sc[i-1][1];
            return 0;
        }
    }

    if (S - sc[N-1][1] >= M) cout << sc[N-1][1];
    else cout << -1;
}