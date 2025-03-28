#include <iostream>
#include <vector>
using namespace std;

int R;

vector<string> fr;
string my;

char info[3] = {'S', 'P', 'R'};


int comp(char x, char y) {
    if (x == y) return 1;
    else if (x == 'S' && y == 'P') return 2;
    else if (x == 'P' && y == 'R') return 2;
    else if (x == 'R' && y == 'S') return 2;
    else return 0;
}

int main() {
    cin >> R;
    cin >> my;

    int answer = 0, total = 0, maxV = 0;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        fr.push_back(s);
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < N; j++) {
            answer += comp(my[i], fr[j][i]);
        }
    }

    cout << answer << '\n';

    int tmp;
    for (int i = 0; i < R; i++) {
        total = 0;
        for (int j = 0; j < 3; j++) {
            tmp = 0;
            for (int k = 0; k < N; k++) {
                tmp += comp(info[j], fr[k][i]);
            }
            total = max(total, tmp);
        }

        maxV += total;
    }

    cout << maxV;
}