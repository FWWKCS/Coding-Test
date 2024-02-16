#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string input;
    int count = 0;
    for (int i =  1; i <= 5; i++) {
        cin >> input;
        if (input.find("FBI") != string::npos) {
            count++;
            cout << i << ' ';
        }
    }

    if (count == 0) cout << "HE GOT AWAY!";
}