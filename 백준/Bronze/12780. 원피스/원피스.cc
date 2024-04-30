#include <iostream>
#include <string>
using namespace std;

int main() {
    string plain; cin >> plain;
    string target; cin >> target;

    int count = 0;

    for (int i = 0; i <= plain.length()-target.length(); i++) {
        if (plain.substr(i, target.length()) == target) count++;
    }

    cout << count;
}