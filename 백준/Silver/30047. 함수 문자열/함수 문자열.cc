#include <iostream>
#include <vector>
#include <string>
using namespace std;

string S;
int idx = 0;
int top = 0;
vector<int> stack;

int main() {
    cin >> S;

    while (idx < S.length()) {
        if (S[idx] == 'x') {
            stack.push_back(0);
            top++;
            idx++;
        }

        else if (S[idx] == 'g') {
            stack.push_back(-2);
            top++;
            idx++;
        }

        else if (S[idx] == 'f') {
            stack.push_back(-3);
            top++;
            idx++;
        }

        while (true) {
            // g
            if (top-2 >= 0 && stack.back() >= 0 && stack[top-2] == -2) {
                int value = stack.back();
                stack.pop_back();
                stack.pop_back();
                stack.push_back(value+1);
                top--;
            }
    
            // f
            else if (top-3 >= 0 && stack[top-2] >= 0 && stack[top-1] >= 0 && stack[top-3] == -3) {
                int s = stack[top-2], t = stack[top-1];
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
                stack.push_back(min(s, t));
                top -= 2;
            }

            else break;
        }
    }

    if (stack.size() != 1 || stack.back() < 0) cout << -1;
    else cout << stack.back();
}