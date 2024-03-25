#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int sh, sm, ss;
    int eh, em, es;
    int total;

    string start, end;

    cin >> start >> end;
    
    sh = stoi(start.substr(0, 2));
    sm = stoi(start.substr(3, 2));
    ss = stoi(start.substr(6, 2));
    
    eh = stoi(end.substr(0, 2));
    em = stoi(end.substr(3, 2));
    es = stoi(end.substr(6, 2));

    total = (eh*3600) + (em*60) + es - (sh*3600) - (sm*60) - ss;

    if (total <= 0) total += 24 * 3600;

    cout << setfill('0') << setw(2) << total / 3600 << ':';
    total %= 3600;
    cout << setfill('0') << setw(2) << total / 60 << ':';
    total %= 60;
    cout << setfill('0') << setw(2) << total;

    
}