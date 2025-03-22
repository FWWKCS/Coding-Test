#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;

int N, M;
vector<int> jw;

int binSearch() {
    int s = 1, e = jw.back();
    int res;

    while (s <= e) {
        int left = N;
        int mid = (s+e)/2;

        int cnt = 0;
        for (int x : jw) {
            if (x % mid == 0) cnt += x / mid;
            else cnt += (x / mid) + 1;
        }

        if (cnt <= N) {
            res = mid;
            e = mid - 1;
        }
        else s = mid + 1;
    }

    return res;
}

int main() {
    FASTIO;

    cin >> N >> M;
    jw.resize(M);
    for (auto &x : jw) cin >> x;

    sort(jw.begin(), jw.end());
    cout << binSearch();
}