#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int X; cin >> X;
    cin.ignore();
    
    int rel[52][52] = {0, };
    for (int i = 0; i < 52; i++) rel[i][i] = 1;

    while (X--) {
        string line;
        getline(cin, line);
        int P = line[0] - 'a' < 0 ? line[0] - 'A' : line[0] - 'a' + 26;
        int Q = line[5] - 'a' < 0 ? line[5] - 'A' : line[5] - 'a' + 26;
        rel[P][Q] = 1;
    }

    for (int k = 0; k < 52; k++) {
        for (int P = 0; P < 52; P++) {
            for (int Q = 0; Q < 52; Q++) {
                if (P == Q) continue;

                if (rel[P][k] && rel[k][Q]) rel[P][Q] = 1;
                
            }
        }
    }

    int total = 0;
    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 52; j++) {
            if (i != j && rel[i][j]) total++;
        }
    }

    cout << total << '\n';
    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 52; j++) {
            if (i != j && rel[i][j]) cout << (i < 26 ? char(i+65) : char(i-26+97)) << " => " << (j < 26 ? char(j+65) : char(j-26+97)) << '\n';
        }
    }

}