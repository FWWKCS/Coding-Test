#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    string value = "";

    while (true) {
        value = to_string(N);
        
        bool found = all_of(value.begin(), value.end(), [](char i) { return i == '4' || i == '7'; });
        if (found) {
            cout << N << '\n';
            break;
        }
        N--;
    }   
}