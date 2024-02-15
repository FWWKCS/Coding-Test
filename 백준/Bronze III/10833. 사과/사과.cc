#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N; cin >> N;
    int rest = 0;
    int students, apples;
    for (int i = 0; i < N; i++) {
        cin >> students >> apples;
        rest += apples % students;
    }

    cout << rest;
}