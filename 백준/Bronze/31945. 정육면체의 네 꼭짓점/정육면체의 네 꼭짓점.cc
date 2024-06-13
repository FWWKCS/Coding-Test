#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> x_is_zero = {0,2,4,6};
    vector<int> x_is_one = {1,3,5,7};
    vector<int> y_is_zero = {0,1,4,5};
    vector<int> y_is_one = {2,3,6,7};
    vector<int> z_is_zero = {0,1,2,3};
    vector<int> z_is_one = {4,5,6,7};

    int T; cin >> T;
    int x;
    for (int i = 0; i < T; i++) {
        vector<int> input;
        for (int j = 0; j < 4; j++) {
            cin >> x;
            input.push_back(x);
        }

        sort(input.begin(), input.end());

        if (input == x_is_zero || input == x_is_one 
         || input == y_is_zero || input == y_is_one
         || input == z_is_zero || input == z_is_one) {
            cout << "YES\n";
            continue;
        }
        else cout << "NO\n";
    }
}