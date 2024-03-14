#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<char> bin;
    string b = ""; 
    cin >> b;

    for (int i = 0; i < b.length(); i++) bin.push_back(b[i]);

    while (bin.size() % 3 != 0) {
        bin.push_front('0');
    }

    b = "";
    string o = "";
    string tmp = "";
    for (int i = 0; i < bin.size(); i++) b += bin[i];

    for (int i = 0; i < b.length() / 3; i++) {
        tmp = b.substr(i*3, 3);
        if (tmp == "000") o += '0';
        else if (tmp == "001") o += '1';
        else if (tmp == "010") o += '2';
        else if (tmp == "011") o += '3';
        else if (tmp == "100") o += '4';
        else if (tmp == "101") o += '5';
        else if (tmp == "110") o += '6';
        else o += '7';
    }
    
    cout << o;
}