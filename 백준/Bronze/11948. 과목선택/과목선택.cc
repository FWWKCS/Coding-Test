#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> science(4, 0);
    vector<int> society(2, 0);

    int x;
    for (int i = 0; i < 4; i++) {
        cin >> x;
        science[i] = x;
    }

    for (int i = 0; i < 2; i++) {
        cin >> x;
        society[i] = x;
    }

    sort(science.begin(), science.end());
    sort(society.begin(), society.end());

    cout << science[1] + science[2] + science[3] + society[1];
}