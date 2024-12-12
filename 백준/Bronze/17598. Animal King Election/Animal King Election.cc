#include <iostream>
using namespace std;

int main() {
    string s;
    int l = 0, t = 0;
    while (getline(cin, s)) {
        if (s == "Lion") l++;
        else t++;
    }
    
    if (l < t) cout << "Tiger";
    else cout << "Lion";
}