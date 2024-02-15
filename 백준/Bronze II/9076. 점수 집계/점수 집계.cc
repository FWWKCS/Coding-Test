#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int T; cin >> T;
    vector<int> score(5);
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> score[j];
        }
        sort(score.begin(), score.end());
        if (score[3]-score[1] >= 4) cout << "KIN\n";
        else cout << accumulate(score.begin()+1, score.end()-1, 0) << '\n';
    }
}