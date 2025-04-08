#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
vector<string> sub;

string check(string t) {
    vector<vector<int>> info(N, vector<int>(2, 0));
    string answer = "";

    for (string x : sub) {
        bool P = true, S = true;
        for (int i = 0; i < x.length(); i++) {
            if (t[i] != x[i]) {
                P = false;
                break;
            }
        }

        for (int i = 0; i < x.length(); i++) {
            if (t[N-x.length()+i] != x[i]) {
                S = false;
                break;
            }
        }

        if (!P && !S) return "";
        else if (P) {
            if (!info[x.length()][0]) { 
                info[x.length()][0] = 1;
                answer += 'P';
            }
            else {
                info[x.length()][1] = 1;
                answer += 'S';
            }
        }   
        else { // S
            if (!info[x.length()][1]) {
                info[x.length()][1] = 1;
                answer += 'S';
            }
            else {
                info[x.length()][0] = 1;
                answer += 'P';
            }
        }
    }

    return answer;
}

int main() {
    cin >> N;
    string x = "", y = "";

    for (int i = 0; i < 2*N-2; i++) {
        string s; cin >> s;
        sub.push_back(s);

        if (s.length() == N-1) {
            if (x.empty()) x = s;
            else y = s;
        }
    }

    bool c1 = true, c2 = true;
    for (int i = 0; i < N-2; i++) {
        if (c1 && x[i+1] != y[i]) c1 = false;
        else if (c2 && x[i] != y[i+1]) c2 = false;
    }

    string C1;
    if (c1) C1 = check(x + y[N-2]);

    string C2;
    if (c2) C2 = check(y + x[N-2]);

    if (!C1.empty()) cout << x + y[N-2] << '\n' << C1;
    else cout << y + x[N-2] << '\n' << C2;
}