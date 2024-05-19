#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C, D; cin >> A >> B >> C >> D;

    int S = 0;
    vector<int> num = { A, B, C, D };
    sort(num.rbegin(), num.rend());

    do {
        if (num[0] >= num[2] && num[1] <= num[3]) {
            S = max(S, num[2]*num[1]);
        }
    } while (prev_permutation(num.begin(), num.end()));

    cout << S;
}