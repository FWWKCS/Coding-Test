#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string input; cin >> input;
        sort(input.begin(), input.end());

        cout << input << '\n';
        while (next_permutation(input.begin(), input.end())) {
            cout << input << '\n';
        }
    }
}