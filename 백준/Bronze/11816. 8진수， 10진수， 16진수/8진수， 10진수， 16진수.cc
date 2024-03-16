#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, int> value = { 
        {'a', 10},
        {'b', 11},
        {'c', 12},
        {'d', 13},
        {'e', 14},
        {'f', 15}
    };

    string data; cin >> data;

    int dec = 0;
    int len = data.length()-1;
    if (data[0] == '0' && data[1] == 'x') {
        // hex
        for (int i = data.length()-1; i > 1; i--) {
            if ('0' <= data[i] && data[i] <= '9') 
                dec += (data[i] - '0') * pow(16, len-i);
            else dec += value[data[i]] * pow(16, len-i);
        }
    }
    else if (data[0] == '0') {
        // oct
        for (int i = data.length()-1; i > 0; i--) {
            if ('0' <= data[i] && data[i] <= '9')
                dec += (data[i] - '0') * pow(8, len-i);
            else dec += value[data[i]] * pow(8, len-i);
        }
    }
    else dec = stoi(data);
    
    cout << dec;
}