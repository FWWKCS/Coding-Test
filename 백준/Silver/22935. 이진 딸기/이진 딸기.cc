#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

vector<string> table(15+13);

int main() {
    FASTIO;
    
    for (int i = 0; i < 15; i++) {
        bitset<4> binary(i+1);
        string b = binary.to_string();

        string s = "";
        for (char c : b) {
            if (c - '0') s += "딸기";
            else s += "V";
        }

        table[i] = s;
    }


    for (int i = 15; i < 15+13; i++) {
        table[i] = table[28 - i];
    }

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        cout << table[((N-1) % 28)] << '\n';
    }
}