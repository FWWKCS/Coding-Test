#include <iostream>
using namespace std;

int main() {
    int p1, s1; cin >> p1 >> s1;
    int s2, p2; cin >> s2 >> p2;

    int p_a, s_a;

    if (p1+p2 < s1+s2) cout << "Esteghlal";
    else if (p1+p2 > s1+s2) cout << "Persepolis";
    else {
        if (p2 < s1) cout << "Esteghlal";
        else if (p2 > s1) cout << "Persepolis";
        else cout << "Penalty";
    }
}