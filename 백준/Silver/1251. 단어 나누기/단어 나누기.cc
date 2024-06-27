#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string target; cin >> target;
    string answer = "";
    for (int i = 0; i < target.length(); i++) answer += 'z';
    
    string s1 = "", s2 = "", s3 = "";
    int s = 0, e = target.length()-1;
    for (int i = 0; i < target.length()-2; i++) {
        for (int j = i+1; j < target.length()-1; j++) {
            // section 1
            s1 = target.substr(s, i+1);
            reverse(s1.begin(), s1.end());

            // section 2
            s2 = target.substr(i+1, j-i);
            reverse(s2.begin(), s2.end());

            // section 3
            s3 = target.substr(j+1, e - j);
            reverse(s3.begin(), s3.end());

            if (s1 + s2 + s3 < answer) answer = s1+s2+s3;
        }
    }

    cout << answer;
}