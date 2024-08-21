#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N; cin >> N;
    string input; cin >> input;

    vector<char> stack;
    for (int i = 0; i < input.length(); i++) {
        if (stack.size() <= 1) {
            stack.push_back(input[i]);
        } else {
            stack.push_back(input[i]);

            string target = "";
            for (int x = stack.size()-3; x < stack.size(); x++) target += stack[x];

            if (target == "PS4" || target == "PS5") stack.pop_back();
        }
    }

    for (auto x : stack) cout << x; 
}