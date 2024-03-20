#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M; cin >> N >> M;
    vector<string> take;
    int i;
    string input;
    for (i = 0; i < N; i++) {
        cin >> input;
        take.push_back(input);
    }

    bool eyfa;
    for (i = 0; i < N; i++) {
        eyfa = true;
        cin >> input;
        for (int k = 0; k < input.length(); k+=2) {
            if (input[k] != take[i][k/2] || input[k+1] != take[i][k/2]) {
                eyfa = false;
                break;
            }
        }
        if (!eyfa) break;
    }
    if (eyfa) cout << "Eyfa";
    else cout << "Not Eyfa";
}