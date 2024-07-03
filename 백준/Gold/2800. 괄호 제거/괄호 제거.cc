#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 1;
    string T; cin >> T;
    int count = 0;
    for (int i = 0; i < T.length(); i++) {
        if (T[i] == '(') count++;
    }

    set<string> value;

    while (n < int(pow(2, count))) {
        string b_n = bitset<10>(n).to_string().substr(10-count, count);
        
        string S = "";
        vector<int> stack;
        int open = 0;
        // 비트에서 1인 부분은 괄호 제거 영역
        for (int x = 0; x < T.length(); x++) {
            if (T[x] == '(') {
                if (b_n[open] == '0') {
                    S += T[x];
                }
                stack.push_back(b_n[open] - '0');
                open++;
            }
            else if (T[x] == ')') {
                if (stack.back() == 0) S += T[x];
                stack.pop_back();
            }
            else S += T[x];
        }
        
        value.insert(S);
        
        n++;
    }

    for (auto v : value) cout << v << '\n';
}