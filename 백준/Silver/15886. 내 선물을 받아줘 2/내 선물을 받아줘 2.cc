#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    string s; cin >> s;

    int answer = 0;

    for (int i = 0; i < N-1; i++) {
        if (s[i] == 'E' && s[i+1] == 'W') answer++;
    }

    cout << answer;
}