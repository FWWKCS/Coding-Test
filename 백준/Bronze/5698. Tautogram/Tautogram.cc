#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string input;
    while (getline(cin, input)) {
        if (input == "*") break;

        bool tautogram = true;
        char target = toupper(input[0]);
        istringstream iss(input);
        string tmp;
        while (iss >> tmp) {
            char val = toupper(tmp[0]);
            if (val != target) {
                tautogram = false;
                break;
            } 
        }

        if (tautogram) cout << "Y\n";
        else cout << "N\n";
    }
}
