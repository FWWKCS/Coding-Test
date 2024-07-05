#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N; cin >> N;
    int count = 0;
    string S;

    for (int i = 0; i < N; i++) {
        vector<char> stack;
        cin >> S;
        for (int k = 0; k < S.length(); k++) {
            if (stack.empty()) stack.push_back(S[k]);
            else if (stack.back() == S[k]) stack.pop_back();
            else stack.push_back(S[k]);
        }

        if (stack.empty()) count++;
    }
    cout << count;
}