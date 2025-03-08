#include <iostream>
#include <cctype>
#include <string>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

string process(string s) {
    string ret = "";
    for (char c : s) {
        // 맨 앞 공백 무시
        if (ret == "" && c == ' ') continue;

        // 알파벳 대문자와 소문자는 구별하지 않는다.
        if (isalpha(c)) {
            if (islower(c)) ret += c;
            else ret += tolower(c);
            continue;
        }

        // 여는 괄호끼리는 종류를 구별하지 않는다.
        if (c == '(' || c == '[' || c == '{') {
            if (!ret.empty() && ret.back() == ' ') ret.pop_back();
            ret += '(';
            continue;
        }

        // 닫는 괄호끼리는 종류를 구별하지 않는다.
        if (c == ')' || c == ']' || c == '}') {
            if (!ret.empty() && ret.back() == ' ') ret.pop_back();
            ret += ')';
            continue;
        }

        if (c == ' ') {
            // 특수문자의 뒤 공백을 무시
            if (ret.back() == ',' 
             || ret.back() == '(' || ret.back() == ')'
             || ret.back() == '{' || ret.back() == '}'
             || ret.back() == '[' || ret.back() == ']') continue;

            // 하나 초과의 공백을 무시
            if (ret.back() == ' ') continue;
        }


        if (c == ',' || c == ';') {
            if (ret.back() == ' ') ret.pop_back();
            ret += ',';
            continue;
        }

        if (c == '.' || c == ':') {
            if (ret.back() == ' ') ret.pop_back();
            ret += c;
            continue;
        }

        ret += c;
    }

    // 뒤의 공백을 제거
    while (ret.back() == ' ') ret.pop_back();

    return ret;
}

int main() {
    FASTIO;

    int K; cin >> K;
    cin.ignore();
    for (int i = 1; i <= K; i++) {
        string x, y; 
        getline(cin, x);
        getline(cin, y);

        cout << "Data Set " << i << ": " << (process(x) == process(y) ? "equal\n" : "not equal\n");
        cout << '\n';
    }
}