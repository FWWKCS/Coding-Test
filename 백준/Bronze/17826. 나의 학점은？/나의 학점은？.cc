#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> score(1, 0);
    for (int i = 0; i < 50; i++) {
        int x; cin >> x;
        score.push_back(x);
    }

    int my; cin >> my;
    int rank;
    for (int i = 1; i <= 50; i++) {
        if (score[i] == my) {
            rank = i;
            break;
        }
    }

    if (1 <= rank && rank <= 5) cout << "A+";
    else if (6 <= rank && rank <= 15) cout << "A0";
    else if (16 <= rank && rank <= 30) cout << "B+";
    else if (31 <= rank && rank <= 35) cout << "B0";
    else if (36 <= rank && rank <= 45) cout << "C+";
    else if (46 <= rank && rank <= 48) cout << "C0";
    else cout << "F";
}