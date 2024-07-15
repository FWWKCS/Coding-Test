#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        bool possible = true;
        vector<int> countX(26, 0), countY(26, 0);
        string X, Y; cin >> X >> Y;

        if (X.length() != Y.length()) {
            cout << "Impossible\n";
            continue;
        }


        for (int k = 0; k < X.length(); k++) {
            countX[X[k]-'a']++;
            countY[Y[k]-'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (countX[i] != countY[i]) {
                possible = false;
                break;
            }
        }

        if (possible) cout << "Possible\n";
        else cout << "Impossible\n";
    }
}