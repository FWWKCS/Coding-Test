#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C; cin >> A >> B >> C;
    vector<int> time(101, 0);
    
    int s, e;
    for (int i = 0; i < 3; i++) {
        cin >> s >> e;
        for (int k = s; k < e; k++) time[k]++;
    }

    int sum = 0;
    for (int i = 1; i < 100; i++) {
        if (time[i] == 0) continue;

        if (time[i] == 1) sum += A;
        else if (time[i] == 2) sum += B * 2;
        else sum += C * 3; 
    }

    cout << sum;
}