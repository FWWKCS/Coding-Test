#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);   
    cin.tie(0);
    cout.tie(0);

    string input;
    set<char> v = {'a', 'e', 'i', 'o', 'u'};
    cin >> input;
    int count = 0;
    for (int i = 0; i < input.length(); i++) {
        if (v.find(input[i]) != v.end()) count++;
    }
    cout << count;
}