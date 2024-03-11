#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    cin.ignore();

    string input, token;
    deque<string> words;
    for (int i = 0; i < N; i++) {
        getline(cin, input);
        stringstream ss(input);
        
        while (ss >> token) words.push_back(token);
        rotate(words.begin(), words.begin()+2, words.end());
        for (int k = 0; k < words.size(); k++) cout << words[k] << ' ';
        cout << '\n';

        words.clear();
    } 
}