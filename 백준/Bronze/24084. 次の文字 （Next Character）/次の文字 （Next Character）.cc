#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    string S; cin >> S;

    for (int i = 0; i < N-1; i++) {
        if (S[i+1] == 'J') cout << S[i] << '\n';
    }
}