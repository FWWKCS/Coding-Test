#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tmp = 0, total = 0;
    int N; cin >> N;
    int dice;

    map<int, int> result;
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < 4; k++) {
            cin >> dice;
            if (result.count(dice) == 0) result[dice] = 1;
            else result[dice]++;
        }

        if (result.size() == 1) {
            for (auto x : result) total = max(total, 50000 + (x.first * 5000));
        }
        else if (result.size() == 2) {
            for (auto x : result) {
                // 같은 눈이 3개인 경우
                if (x.second == 3) {
                    total = max(total, 10000 + (x.first * 1000));
                    break;
                } 
                // 같은 눈이 2개인 경우
                else if (x.second == 2) tmp += (x.first) * 500;
            }
            if (tmp > 0) {
                tmp += 2000;
                total = max(total, tmp);
            } 
        }
        else if (result.size() == 3) {
            for (auto x : result) {
                if (x.second == 2) {
                    total = max(total, 1000 + (x.first * 100));
                    break;
                }
            }
        }
        else {
            int found = 0;
            for (auto x : result) {
                found = max(found, x.first);
            }
            total = max(total, found * 100);
        }

        tmp = 0;
        result.clear();
    }
    cout << total;
}