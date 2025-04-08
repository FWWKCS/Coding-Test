#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int answer;
    char target;

    char cur; cin >> cur;
    char opr, X;
    for (int i = 1; i < N-2; i+=2) {
        cin >> opr >> X;
        if (opr == '&') {
            if (cur == 'T' && X == 'T') cur = 'T';
            else cur = 'F';
        }
        else {
            if (cur == 'F' && X == 'F') cur = 'F';
            else cur = 'T';
        }
    }

    if (N > 1) cin >> opr >> X;
    cin >> target;
    if (N == 1) {
        cout << (cur != target ? 1 : 0);
        return 0;
    }

    char result;

    if (opr == '&') {
        if (cur == 'T' && X == 'T') result = 'T';
        else result = 'F';
    }
    else {
        if (cur == 'F' && X == 'F') result = 'F';
        else result = 'T';
    }

    if (target == result) answer = 0;
    else {
        if (opr == '&') {
            if (cur == 'F' && X == 'F') answer = 2;
            else answer = 1;
        }
        else {
            if (cur == 'T' && X == 'T') answer = 2;
            else answer = 1;
        }
    }

    cout << answer;
}