#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
    string input;
    string tmp;
    while (true) {
        cin >> input;
        if (input == "#") break;

        int i = 0;
        for (; i < input.length(); i++) {
            if (vowel.find(input[i]) != vowel.end()) {
                if (i != 0) tmp = input.substr(0, i);
                break;
            }
        }

        if (i == input.length()) cout << input;
        else for (; i < input.length(); i++) cout << input[i];
        
        cout << tmp << "ay\n";
        tmp = "";
    }   
}