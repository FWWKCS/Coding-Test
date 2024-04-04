#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K; cin >> N >> K;

    int deleted = -1;
    int count = 0;
    vector<int> table;
    for (int i = 0; i <= N; i++) table.push_back(i);
    table[1] = 0;

    while (count != K) {
        int P = 0;
        while (true) {
            if (table[P] != 0) break;
            P++;
        }

        deleted = P;
        table[P] = 0;
        count++;
        if (count == K) break;

        for (int x = 2; x*P <= N; x++) {
            if (table[x*P] == 0) continue;
            deleted = x * P;
            table[x * P] = 0;
            count++;
            if (count == K) break;
        }
    }

    cout << deleted;
}