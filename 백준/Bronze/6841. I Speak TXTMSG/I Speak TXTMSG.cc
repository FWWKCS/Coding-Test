#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, string> form = {
        {"CU", "see you"},
        {":-)", "I’m happy"},
        {":-(", "I’m unhappy"},
        {";-)", "wink"},
        {":-P", "stick out my tongue"},
        {"(~.~)", "sleepy"},
        {"TA", "totally awesome"},
        {"CCC", "Canadian Computing Competition"},
        {"CUZ", "because"},
        {"TY", "thank-you"},
        {"YW", "you’re welcome"},
        {"TTYL", "talk to you later"}
    };

    string S;
    while (getline(cin, S)) {
        if (S == "EOF") return 0;

        if (form.find(S) != form.end()) cout << form[S] << '\n';
        else cout << S << '\n';
    }
}