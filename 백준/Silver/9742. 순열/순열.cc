#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string input, target;
    int k;
    bool exist;

    while (getline(cin, input)) {
        if (input == "EOF") break;
        exist = true;

        istringstream iss(input);
        iss >> target >> k;

        for (int i = 0; i < k-1; i++) {
            bool found = next_permutation(target.begin(), target.end());
            if (!found) {
                exist = false;
                break;
            }
        }

        if (exist) {
            cout << input << " = " << target << '\n';
        }
        else cout << input << " = No permutation\n";
    }
}