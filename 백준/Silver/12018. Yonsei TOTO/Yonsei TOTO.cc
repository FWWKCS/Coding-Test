#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int result;

    int n,m; cin >> n >> m;
    vector<int> synth;
    for (int i = 0; i < n; i++) {
        int P, L; cin >> P >> L;
        vector<int> total;
        for (int k = 0; k < P; k++) {
            int x; cin >> x;
            total.push_back(x);
        }
        // sort
        sort(total.rbegin(), total.rend());

        if (P < L) synth.push_back(1);

        // 상위 L명만 필터링
        // L등인 학생과 같은 마일리지
        else synth.push_back(total[L-1]);
    }

    // sort
    sort(synth.begin(), synth.end());

    // prefix sum
    for (int i = 1; i < n; i++) 
        synth[i] += synth[i-1];

    for (int i = 0; i < n; i++) {
        if (synth[i] <= m) {
            result = i+1;
        }
    }

    cout << result;
}