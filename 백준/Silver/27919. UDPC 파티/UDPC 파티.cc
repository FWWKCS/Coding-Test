#include <iostream>
using namespace std;

int main() {
    string s; cin >> s;
    int U = 0, D = 0, P = 0, C = 0;
    for (char c : s) {
        if (c == 'U') U++;
        else if (c == 'D') D++;
        else if (c == 'P') P++;
        else C++;
    }    

    int tD = (P+D)/2;
    int tP = (P+D)-tD;

    // U가 P, D보다 많을 수 있는지 검사
    if (U+C > tD && U+C > tP) cout << 'U';

    // D, P는 둘 중 하나만 있어도 모두 가능
    if (D != 0 || P != 0) cout << "DP";
}