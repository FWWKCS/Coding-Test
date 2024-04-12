#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    string input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        bool found = next_permutation(input.begin(), input.end());
        if (found) cout << input << '\n';
        else cout << "BIGGEST\n";
    }
}