#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    deque<char> bin;
    string b = ""; 
    cin >> b;

    for (int i = 0; i < b.length(); i++) bin.push_back(b[i]);

    while (bin.size() % 3 != 0) {
        bin.push_front('0');
    }

    b = "";
    for (int i = 0; i < bin.size(); i++) b += bin[i];

    stack<int> oct;
    for (int i = b.length()-1; i >= 0; i-=3) {
        int tmp = b[i] - '0';
        tmp += 2 * (b[i-1] - '0');
        tmp += 4 * (b[i-2] - '0');

        oct.push(tmp);
    }
    
    while (!oct.empty()) cout << oct.top(), oct.pop();
}