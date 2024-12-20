#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C; cin >> A >> B >> C;
    vector<int> L = {A, B, C};
    sort(L.begin(), L.end());

    cout << L[1] + L[2];
}