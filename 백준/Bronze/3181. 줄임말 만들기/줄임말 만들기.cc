#include <bits/stdc++.h>
using namespace std;

int main() {
    set<string> keyword = {"i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili"};

    string line;
    getline(cin, line);
    istringstream is(line);

    string word;
    int count = 1;
    while (is >> word) {
        if (keyword.find(word) == keyword.end())  
            cout << char(toupper(word[0]));
        else if (count == 1) {
            cout << char(toupper(word[0]));
        }
        count++;
    }
}