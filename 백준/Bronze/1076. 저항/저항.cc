#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    long long result = 0;
    map<string, int> R = {
        {"black", 0},
        {"brown", 1},
        {"red", 2},
        {"orange", 3},
        {"yellow", 4},
        {"green", 5},
        {"blue", 6},
        {"violet", 7},
        {"grey", 8},
        {"white", 9}
    };

    string value = "";
    cin >> input;
    value += to_string(R[input]);
    cin >> input;
    value += to_string(R[input]);
    
    cin >> input;
    result = stoi(value) * pow(10, R[input]);
    cout << result;
}