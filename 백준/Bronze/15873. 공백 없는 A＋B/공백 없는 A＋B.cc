#include <iostream>
#include <string>
using namespace std;

int main() {
    string N; 
    getline(cin, N);
    
    if (N.length() == 2) cout << N[0] - '0' + N[1] - '0';
    else if (N.length() == 3) {
        if (stoi(N.substr(0, 2)) > 10) {
            cout << N[0] - '0' + stoi(N.substr(1, 2));
        }
        else cout << stoi(N.substr(0, 2)) + N[2] - '0';
    }
    else cout << stoi(N.substr(0, 2)) + stoi(N.substr(2, 2));
}