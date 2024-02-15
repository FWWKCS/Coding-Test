#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N; cin >> N;
    vector<int> result(N);
    for (int i = 0; i < N; i++) cin >> result[i];
    int current = 0;
    int score = 0;
    for (int i = 0; i < N; i++) {
        if (result[i] == 1) {
            current++; score += current;
        } 
        else current = 0;
    }
    cout << score;
}