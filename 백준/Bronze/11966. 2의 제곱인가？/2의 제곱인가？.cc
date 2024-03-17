#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;

    vector<int> value;

    for (int i = 0; i <= 30; i++) value.push_back(pow(2, i));

    if (find(value.begin(), value.end(), N) != value.end()) cout << 1;
    else cout << 0; 
}