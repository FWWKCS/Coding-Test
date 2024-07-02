#include <iostream>
#include <vector>
using namespace std;

int main() {
    string S; cin >> S;
    vector<string> stack;
    int idx, total;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == ')') {
            // 가장 마지막 괄호가 ( 인지 체크
            idx = stack.size()-1;
            total = 0;
            while (idx > -1 && stack[idx] != "(") {
                if (stack[idx] == "[" || stack[idx] == "]") {
                    // invalid
                    cout << 0;
                    return 0;
                }
                else {
                    total += stoi(stack[idx]);
                    stack.pop_back();
                    idx--;
                }
            }
            if (idx == -1) {
                // invalid
                cout << 0;
                return 0;
            }
            if (total == 0) total = 1;

            stack.pop_back();
            stack.push_back(to_string(2*total));
        }
        else if (S[i] == ']') {
            // 가장 마지막 괄호가 [ 인지 체크
            idx = stack.size()-1;
            total = 0;
            while (idx > -1 && stack[idx] != "[") {
                if (stack[idx] == "(" || stack[idx] == ")") {
                    // invalid
                    cout << 0;
                    return 0;
                }
                else {
                    total += stoi(stack[idx]);
                    stack.pop_back();
                    idx--;
                }
            }
            if (idx == -1) {
                // invalid
                cout << 0;
                return 0;
            }

            if (total == 0) total = 1;

            stack.pop_back();
            stack.push_back(to_string(3*total));
        }
        else stack.push_back(string(1, S[i]));
    }

    int answer = 0;
    for (int i = 0; i < stack.size(); i++) {
        if (stack[i] == "(" || stack[i] == ")" || stack[i] == "[" || stack[i] == "]") {
            // remain invalid
            cout << 0;
            return 0;
        }
        answer += stoi(stack[i]);
    }

    cout << answer;
}