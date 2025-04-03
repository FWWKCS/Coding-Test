#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#define FATSIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, q;
vector<string> words;
unordered_set<string> d;

bool case1(string l, string s) {
    // 순서 체크
    int il = 0, is = 0;
    bool f_error = false; // 최초 오류
    while (is < s.length()) {
        if (l[il] != s[is]) {
            if (!f_error) {
                il++;
                f_error = true;
            }
            else return false;
        }
        else il++, is++;
        
    }

    return true;
}

bool case2(string x, string y) {
    // 한 글자만을 제외한 순서 체크
    int ix = 0, iy = 0;
    bool f_error = false; // 최초 오류
    while (ix < x.length()) {
        if (x[ix] != y[iy]) {
            if (!f_error) {
                f_error = true;
                ix++, iy++;
            }
            else return false;
        }
        else ix++, iy++;
    }

    return true;
}

bool case3(string x, string y) {
    // 인접 두자리를 교환하며 검사
    for (int i = 0; i < x.length()-1; i++) {
        swap(x[i], x[i+1]);
        if (x == y) return true;

        swap(x[i], x[i+1]);
    }
    return false;
}

int main() {
    FATSIO;

    cin >> n;
    while (n--) {
        string s; cin >> s;
        if (d.find(s) != d.end()) continue;
        else {
            words.push_back(s);
            d.insert(s);
        }
    }

    cin >> q;
    while (q--) {
        string x; cin >> x;
        bool c1 = false, c2 = false, c3 = false;
        string target = "";
        bool found = false;
        if (d.find(x) != d.end()) cout << x << " is correct\n";
        else {
            for (string s : words) {
                if (abs(long(s.length()-x.length())) == 1) {
                    if (s.length() < x.length()) c1 = case1(x, s);
                    else c1 = case1(s, x);
                } 
                else if (s.length() == x.length()) {
                    c2 = case2(s, x);
                    c3 = case3(s, x);
                }
            
                if (c1 || c2 || c3) {
                    target = s;
                    break;
                }    
            }

            if (!target.empty()) cout << x << " is a misspelling of " << target << '\n';
            else cout << x << " is unknown\n";
        }
    }
}