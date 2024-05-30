#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> count(26, 0);

    string S; cin >> S;

    for (int i = 0; i < S.length(); i++) {
        count[S[i] - 'A']++;
    }

    // validation
    bool validate = true;
    char odd = ' ';

    if (S.length() % 2 == 0) {
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                validate = false;
                break;
            }
        }
    }
    else {
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 == 1) {
                if (odd != ' ') {
                    validate = false;
                    break;
                } 
                else odd = char(i + 'A');
            }
        }

        if (odd == ' ') validate = false;
    }

    if (!validate) cout << "I'm Sorry Hansoo";
    else {
        string answer = "";
        int idx = 0;
        
        while (answer.length() < S.length()/2) {
            for (int k = 0; k < count[idx] / 2; k++) {
                answer += char(idx + 'A');
            }
            idx++;
        }

        if (S.length() % 2 == 1) {
            answer += odd;
            for (int i = answer.length() - 2; i > -1; i--) answer += answer[i];
        }
        else {
            for (int i = answer.length()-1; i > -1; i--) answer += answer[i];
        }

        cout << answer;
    }
}