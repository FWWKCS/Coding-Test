#include <string>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string input;
    int N; cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++) {
        getline(cin, input);

        if (input.substr(0, 10) == "Simon says") {
            cout << input.substr(10, -1);
            cout << '\n';
        }
    }
}