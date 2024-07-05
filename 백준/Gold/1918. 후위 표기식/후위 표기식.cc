#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S; cin >> S;
    vector<char> stack;
    map<char, int> opr = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2}
    };
    int g = 0;
    string answer = "";

    for (int i = 0; i < S.length(); i++) {
        if ('A' <= S[i] && S[i] <= 'Z') {
            answer += S[i];
        } 
        else if (S[i] == '(') {
            g++;
            stack.push_back('(');
        }
        else if (S[i] == ')') {
            // ( 에 도달할 때까지 pop
            while (stack.back() != '(') {
                answer += stack.back();
                stack.pop_back();
            }
            stack.pop_back(); // ( 제거
            g--;
        }
        else {
            // top보다 낮거나 같은 우선순위의 연산자가 들어오면 (를 발견하거나, 스택이 빌 때까지 pop후 push
            while (g > 0 ? stack.back() != '(' : !stack.empty()) {
                if (opr[stack.back()] < opr[S[i]]) break;
                answer += stack.back();
                stack.pop_back();
            }
            stack.push_back(S[i]);
        }
    }  

    while (!stack.empty()) {
        answer += stack.back();
        stack.pop_back();
    }  

    cout << answer;
}