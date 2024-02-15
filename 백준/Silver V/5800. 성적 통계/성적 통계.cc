#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int K; cin >> K;
    int count;
    for (int x = 0; x < K; x++) {
        cin >> count;
        vector<int> score(count);
        for (int i = 0; i < count; i++) cin >> score[i];

        int gap = 0;
        sort(score.begin(), score.end());
        for (int i = 1; i < count; i++) {
            if (gap < score[i]-score[i-1]) gap = score[i] - score[i-1];
        }

        cout << "Class " << x+1 << '\n';
        cout << "Max " << score[count-1] << ", Min " << score[0] << ", Largest gap " << gap << '\n';
    }
}