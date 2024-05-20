#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string input; cin >> input;
    input += '/';

    vector<int> info;
    string num = "";
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '/') {
            info.push_back(stoi(num));
            num = "";
        }
        else num += input[i];
    }

    if ((info[0]+info[2] < info[1]) || (info[1] == 0)) cout << "hasu";
    else cout << "gosu";
}