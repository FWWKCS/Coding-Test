#include <iostream>
#include <vector>
using namespace std;

vector<string> info1 = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
    "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

vector<string> info2 = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

vector<string> info3 = {"",  "onehundred", "twohundred", "threehundred", "fourhundred", "fivehundred", "sixhundred", "sevenhundred", "eighthundred", "ninehundred"};

string NtoS(int k) {
    string s = "";
    
    s += info3[k/100];
    if (k%100 < 20) s += info1[k%100];
    else {
        s += info2[(k%100)/10];
        s += info1[k%10];
    }
    return s;
}

int main() {
    int N; cin >> N;
    int total = 0;
    vector<string> words(N);
    int idx;

    for (int i = 0; i < N; i++) {
        cin >> words[i];
        if (words[i] == "$") idx = i;
        else total += words[i].length();
    }

    for (int i = 1; i < 1000; i++) {
        string s = NtoS(i);
        if (total + s.length() == i) {
            words[idx] = s;
            break;
        }
    }

    for (auto s : words) cout << s << ' ';
}