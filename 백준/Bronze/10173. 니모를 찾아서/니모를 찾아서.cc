#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string input;
    while (getline(cin, input)) {
        if (input == "EOI") return 0;
        for (int i = 0; i < input.length(); i++) input[i] = tolower(input[i]);
        
        if (input.find("nemo") != string::npos) cout << "Found\n";
        else cout << "Missing\n";
    }
}